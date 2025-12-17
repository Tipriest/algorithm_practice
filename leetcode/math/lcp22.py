from typing import List
from queue import Queue


class Solution:
    def paintingPlan(self, n: int, target: int) -> int:
        def factorial(n: int) -> int:
            if n < 1:
                print("invalid input")
            if n == 1:
                return 1
            return n * factorial(n - 1)

        def select(n: int, x: int) -> int:
            if n < x:
                print("invalid input")
            if n <= 0 or x < 0:
                print("invalid input")
            if 0 == x:
                return 1
            return factorial(n) // (factorial(x) * factorial(n - x))

        if target == n * n:
            return 1
        elif target == 0:
            return 1
        res: int = 0
        for x in range(n):
            if target - n * x < 0:
                break
            elif 0 == (target - n * x) % (n - x):
                y: int = (target - n * x) // (n - x)
                res += select(n, x) * select(n, y)
            else:
                continue
        return res


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    result = solution.paintingPlan(4, 13)
    print(f"result = {result}")
