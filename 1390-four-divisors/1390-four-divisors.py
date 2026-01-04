from typing import List
import math

class Solution(object):
    def isPrime(self, n: int) ->bool:
        if n < 2:
            return False
        i = 2
        while i * i <= n:
            if n % i ==0:
                return False
            i += 1
        return True

    def sumFourDivisors(self, nums: List[int]) -> int:
        total = 0
        for x in nums:
            # Case 1 : p^3 == x
            p = round(x**(1/3))
            if p ** 3 == x and self.isPrime(p):
                total += 1 + p + p*p + x
                continue
            
            # Case 2 : p*q == x
            i = 2
            while i * i <= x:
                if x % i == 0:
                    j = x//i
                    if i != j and self.isPrime(j):
                        total += 1 + i + j + x
                    break
                i += 1
        return total
