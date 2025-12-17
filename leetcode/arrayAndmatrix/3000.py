from typing import List
from queue import Queue


class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_square_bound: int = 0
        max_area: int = 0
        for dimension in dimensions:
            temp: int = pow(dimension[0], 2) + pow(dimension[1], 2)
            if temp == max_square_bound:
                # max_square_bound = temp
                max_area = max(max_area, dimension[0] * dimension[1])
            elif temp > max_square_bound:
                max_square_bound = temp
                max_area = dimension[0] * dimension[1]
        return max_area


if __name__ == "__main__":
    solution = Solution()
    nums: List[List[int]] = [[9, 3], [8, 6]]
    result = solution.areaOfMaxDiagonal(nums)
    print(f"result = {result}")
