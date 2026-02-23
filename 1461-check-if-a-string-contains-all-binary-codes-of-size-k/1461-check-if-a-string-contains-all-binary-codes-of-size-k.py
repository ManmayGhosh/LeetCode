class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        actual = 1 << k

        if len(s) - k + 1 < actual:
            return False

        seen = set()

        for i in range(len(s) - k + 1):
            seen.add(s[i:i+k])

        return len(seen) == actual