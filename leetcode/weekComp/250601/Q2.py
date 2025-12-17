from typing import List
from queue import Queue


class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m1 = len(grid)
        n1 = len(grid[0])
        m2 = m1 - k + 1
        n2 = n1 - k + 1
        result = [[0 for i in range(n2)] for j in range(m2)]
        if k == 1:
            return result

        def findClosetValue(mat):
            # 将子矩阵所有元素拉平成一维数组
            arr = []
            for row in mat:
                arr.extend(row)
            arr = set(arr)
            if len(arr) == 1:
                return 0
            arr = list(arr)
            arr.sort()
            min_diff = float("inf")
            # 找最小绝对差
            for i in range(1, len(arr)):
                min_diff = min(min_diff, abs(arr[i] - arr[i - 1]))
            return min_diff

        for i in range(m2):
            for j in range(n2):
                mat = [row[j : j + k] for row in grid[i : i + k]]
                result[i][j] = findClosetValue(mat)
        return result


if __name__ == "__main__":
    solution = Solution()
    grid = [[1, -2, 3], [2, 3, 5], [4, 5, 7]]
    result = solution.minAbsDiff(grid, 2)
    print(f"result = {result}")
