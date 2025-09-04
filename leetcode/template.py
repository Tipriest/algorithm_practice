from typing import List
from queue import Queue
class Solution:
    def sumBase(self, n: int, k: int) -> int:
        return 0
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.sumBase(1, 1)
    print(f"result = {result}")