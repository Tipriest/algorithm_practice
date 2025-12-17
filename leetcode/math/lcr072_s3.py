from typing import List
from queue import Queue
import math


class Solution:
    def mySqrt(self, x: int) -> int:
        if 0 == x:
            return 0
        C: int = x
        x0: float = x
        xi: float
        while True:
            xi = 0.5 * (x0 + C / x0)
            if math.fabs(xi - x0) < 1e-7:
                break
            else:
                x0 = xi
        return int(xi)


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    result = solution.mySqrt(4)
    print(f"result = {result}")
