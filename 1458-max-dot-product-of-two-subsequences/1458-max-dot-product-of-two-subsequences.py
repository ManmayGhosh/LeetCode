class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        memo = {}
        def dp(i,j):

            if i == len(nums1) or j == len(nums2):
                return float("-inf") # if we are passed the boundary, dont pick anything from there.

            if (i,j) in memo:
                return memo[(i,j)]

            taken = nums1[i] * nums2[j]
            res = max(
            # taken i,j. move forward
                taken + dp(i+1, j+1),
            # taken this subsequence and just end.
                taken,
            # skip i: i+1,j
                dp(i+1,j),
            # skip j: i,j+1
                dp(i,j+1),
            )

            memo[(i,j)] = res

            return memo[(i,j)]

        return dp(0,0)