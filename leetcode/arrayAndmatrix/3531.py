from typing import List
from queue import Queue


class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        row_min: List[int] = [n + 1] * (n + 1)
        col_min: List[int] = [n + 1] * (n + 1)
        row_max: List[int] = [0] * (n + 1)
        col_max: List[int] = [0] * (n + 1)
        for x, y in buildings:
            row_min[x] = min(row_min[x], y)
            row_max[x] = max(row_max[x], y)
            col_min[y] = min(col_min[y], x)
            col_max[y] = max(col_max[y], x)
        res: int = 0
        for x, y in buildings:
            if (
                x > col_min[y]
                and x < col_max[y]
                and y > row_min[x]
                and y < row_max[x]
            ):
                res += 1
        return res


if __name__ == "__main__":
    solution = Solution()
    n = 5
    buildings = [[1, 3], [3, 2], [3, 3], [3, 5], [5, 3]]
    result = solution.countCoveredBuildings(n, buildings)
    print(f"result = {result}")
