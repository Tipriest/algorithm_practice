from typing import List
from queue import Queue
class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m:int =  len(grid)
        n:int = len(grid[0])
        res:int = 0
        for j in range(n):
            curCol:int = 1
            curLine:int = j
            while curCol < m:
                if grid[curCol][j] < grid[curCol-1][j]+1:
                    res += grid[curCol - 1][j] + 1 - grid[curCol][j]
                    grid[curCol][j] = grid[curCol - 1][j] + 1
                    curCol+=1
                else:
                    curCol+=1
                    continue
        return res
if __name__ == "__main__":
    solution = Solution()
    grid = [[3,2,1],[2,1,0],[1,2,3]]
    result = solution.minimumOperations(grid)
    print(f"result = {result}")
 