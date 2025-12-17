from typing import List
from queue import Queue


class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        m: int = len(grid)
        n: int = len(grid[0])
        for i in range(m):
            for j in range(n):
                if i == j or n - 1 == i + j:
                    if 0 == grid[i][j]:
                        return False
                    else:
                        continue
                else:
                    if 0 != grid[i][j]:
                        return False
                    else:
                        continue
        return True


if __name__ == "__main__":
    solution = Solution()
    grid = [[2, 0, 0, 1], [0, 3, 1, 0], [0, 5, 2, 0], [4, 0, 0, 2]]
    result = solution.checkXMatrix(grid)
    print(f"result = {result}")
