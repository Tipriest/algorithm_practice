from typing import List
from queue import Queue
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if 0 == low % 2:
            low += 1
        if 0 == high % 2:
            high -= 1
        if low > high:
            return 0
        elif low == high:
            return 1
        else:
            return int((high-low)/2)+1
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.countOdds(2, 10)
    print(f"result = {result}")
