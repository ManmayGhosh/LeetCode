class Solution(object):
    def maxSideLength(self, mat, threshold):
        m, n = len(mat), len(mat[0])

        pref = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                pref[i][j] = (
                    mat[i-1][j-1]
                    + pref[i-1][j]      # sum from top
                    + pref[i][j-1]      # sum from left
                    - pref[i-1][j-1]    # remove double counted area calc in top, left
                )

        maxSide = 0; # stores the largest valid square size found

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                offset = maxSide + 1; # check only the next larger square
                if (i >= offset and j >= offset):
                    s = (
                        pref[i][j]
                        - pref[i][j - offset]
                        - pref[i - offset][j]
                        + pref[i - offset][j - offset]
                    )
                    if s <= threshold:
                        maxSide += 1
        return maxSide