from typing import List
from queue import Queue
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m:int = len(matrix)
        n:int = len(matrix[0])
        k_max:int = min(m, n)+1
        result:int = 0
        for k in range(1, k_max+1):
            for i in range(0, m-k+1):
                for j in range(0, n-k+1):
                    if matrix[i][j] and 1 == k:
                        result += 1
                    elif matrix[i][j]:
                        matrix[i][j] = matrix[i+1][j] and matrix[i][j+1] and matrix[i+1][j+1]
                        result += matrix[i][j]
        return result
if __name__ == "__main__":
    solution = Solution()
    grid = [[0,1,1,1],[1,1,1,1],[0,1,1,1]]
    result = solution.countSquares(grid)
    print(f"result = {result}")
 