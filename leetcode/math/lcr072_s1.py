from typing import List
from queue import Queue
import math
class Solution:
    def mySqrt(self, x: int) -> int:
        if 0 == x:
            return 0
        res:int = int(math.exp(0.5*math.log(x)))
        if pow(res+1, 2)<=x:
            return res+1
        return res
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.mySqrt(4)
    print(f"result = {result}")
 