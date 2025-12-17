from typing import List
from queue import Queue


class Solution:
    def toLowerCase(self, s: str) -> str:
        return s.lower()


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    result = solution.toLowerCase("leeTcode")
    print(f"result = {result}")
