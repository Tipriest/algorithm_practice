from typing import List
from queue import Queue


class Solution:

    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        def calSteps(pa: List[int], pb: List[int]):
            dx: int = abs(pa[0] - pb[0])
            dy: int = abs(pa[1] - pb[1])
            return min(dx, dy) + abs(dx - dy)

        n: int = len(points)
        res: int = 0
        for i in range(n - 1):
            res += calSteps(points[i], points[i + 1])
        return res


if __name__ == "__main__":
    solution = Solution()
    grid = [[1, 1], [3, 4], [-1, 0]]
    result = solution.minTimeToVisitAllPoints(grid)
    print(f"result = {result}")
