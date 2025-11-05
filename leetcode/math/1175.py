from math import sqrt
from typing import List
from queue import Queue
class Solution:
    mod:int = 10 ** 9 + 7
    def numPrimeArrangements(self, n: int) -> int:
        def isPrime(n:int) ->int:
            if 1 == n:
                return 0
            for i in range(2, int(sqrt(n))+1):
                if 0 == n % i:
                    return 0
            return 1
        def factorial(n:int)->int:
            res:int = 1
            for i in range(1, n+1):
                res *= i
                res %= self.mod
            return int(res)
        numPrimes:int = sum(isPrime(i) for i in range(1, n+1))
        return int(factorial(numPrimes)*factorial(n - numPrimes)%self.mod)
                
            
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.numPrimeArrangements(100)
    print(f"result = {result}")
 