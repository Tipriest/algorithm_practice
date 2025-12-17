from typing import List
from queue import Queue


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        result: List[int] = []
        m: int = len(mat)
        n: int = len(mat[0])
        reverse: bool = False
        for i in range(m):
            temp: List[int] = []
            x: int = i
            y: int = 0
            while x >= 0 and y < n:
                temp.append(mat[x][y])
                x -= 1
                y += 1
            if reverse:
                for _t in temp[::-1]:
                    result.append(_t)
            else:
                for _t in temp[::]:
                    result.append(_t)
            reverse = not reverse
        for i in range(1, n):
            temp: List[int] = []
            x: int = m - 1
            y: int = i
            while x >= 0 and y < n:
                temp.append(mat[x][y])
                x -= 1
                y += 1
            if reverse:
                for _t in temp[::-1]:
                    result.append(_t)
            else:
                for _t in temp[::]:
                    result.append(_t)
            reverse = not reverse
        return result


if __name__ == "__main__":
    solution = Solution()
    map = [[2, 3]]
    result = solution.findDiagonalOrder(map)
    print(f"result = {result}")
