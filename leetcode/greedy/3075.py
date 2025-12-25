from typing import List
from queue import Queue
from functools import cache

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        res = 0
        for i in range(k):
            res += happiness[i] - i if (happiness[i] - i) >= 0 else 0
        return res



if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.numIslands(grid)
    print(f"result = {result}")
