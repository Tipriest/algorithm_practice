from typing import List
from queue import Queue


class Solution:
    def calculate(self, s: str) -> int:
        x: int = 1
        y: int = 0
        for ch in s:
            if "A" == ch:
                x = 2 * x + y
            else:
                y = 2 * y + x
        return x + y


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    result = solution.calculate("AB")
    print(f"result = {result}")
