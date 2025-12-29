from typing import List
from queue import Queue


# from functools import cache
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = m * n
        last_col = n
        for i in range(m):
            for j in range(last_col):
                if grid[i][j] >= 0:
                    res -= 1
                else:
                    last_col = j
                    break
        return res


if __name__ == "__main__":
    solution = Solution()
    grid = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
    result = solution.countNegatives(grid)
    print(f"result = {result}")
