from typing import List
from queue import Queue
class Solution:
    def checkDivisibility(self, n: int) -> int:
        def findNumSum(n:int) -> int:
            res:int = 0
            while 0 != n:
                res += n % 10
                n //= 10
            return res
        def findNumMul(n:int) -> int:
            res:int = 1
            while 0 != n:
                res *= n % 10
                n //= 10
            return res
        a:int = findNumSum(n)
        b:int = findNumMul(n)
        if 0 == n % (a + b):
            return True
        return False
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.checkDivisibility(99)
    print(f"result = {result}")
 