from typing import List
from queue import Queue
from math import sqrt

class Solution:
    def sqrttable(self, n : int) -> bool:
        sqrt_n:int = int(sqrt(n))
        return pow(sqrt_n,2)==n
    def countTriples(self, n: int) -> int:
        s_n:int = pow(n,2)
        res:int = 0
        for i in range(1,n):
            for j in range(i+1,n):
                temp:int = pow(i,2)+pow(j,2)
                if temp > s_n:
                    break
                elif not self.sqrttable(temp):
                    continue
                else:
                    res+=2
        return res

if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.countTriples(10)
    print(f"result = {result}")
