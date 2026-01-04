from typing import List
import math

class Solution(object):
# use dp to store whether a number is prime or not for a given range here dp is sieve
    def buildSieve(self, n: int):
        sieve = [True] * (n + 1)
        if n >= 0:
            sieve[0] = False
        if n >= 1:
            sieve[1] = False
        p = 2
        while p * p <= n:
            if sieve[p]:
                # this if if sieve[p]: is done if alreday false means composite number then 
                # its multiple will aslo be composite which will be removed by the prime 
                # factor already so why waste computation
                for multiple in range(p*p, n+1, p):
                    sieve[multiple] = False
            p += 1
        return sieve

    def sumFourDivisors(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_num = max(nums)
        if max_num < 2:
            return 0
        sieve = self.buildSieve(max_num)

        total = 0
        for x in nums:
            # Case 1 : p^3 == x
            p = round(x**(1/3))
            if p >= 0 and p <= max_num and p**3 == x and sieve[p]:
                total += 1 + p + p*p + x
                continue
            
            # Case 2 : p*q == x
            i = 2
            while i * i <= x:
                if x % i == 0:
                    j = x//i
                    if i != j and i <= max_num and j <= max_num and sieve[i] and sieve[j]:
                        total += 1 + i + j + x
                    break
                i += 1
        return total
