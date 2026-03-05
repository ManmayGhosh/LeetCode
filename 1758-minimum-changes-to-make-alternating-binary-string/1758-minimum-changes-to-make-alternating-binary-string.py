class Solution:
    def minOperations(self, s: str) -> int:
        curr1 = 0
        curr2 = 0
        for i in range(len(s)):
            expected1 = '0' if i % 2 == 0 else '1'
            expected2 = '1' if i % 2 == 0 else '0'
            if s[i] != expected1:
                curr1 += 1
            if s[i] != expected2:
                curr2 += 1
        return min(curr1, curr2)