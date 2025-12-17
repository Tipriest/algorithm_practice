from typing import List
from queue import Queue


class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        max_id: int = 0
        max_sum: int = 0
        for i in range(len(mat)):
            m: int = sum(mat[i])
            if m > max_sum:
                max_id = i
                max_sum = m
        return [max_id, max_sum]


if __name__ == "__main__":
    solution = Solution()
    grid = [[0, 1], [1, 0]]
    result = solution.rowAndMaximumOnes(grid)
    print(f"result = {result}")
