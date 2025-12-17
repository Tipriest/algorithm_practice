from typing import List
from queue import Queue
import math


class Solution:
    def mySqrt(self, x: int) -> int:
        l: int = 0
        r: int = x
        ans: int = -1
        while l <= r:
            mid: int = l + (r - l) // 2
            if x < mid * mid:
                r = mid - 1
            elif x == mid * mid:
                return mid
            else:
                l = mid + 1
                ans = mid
        return ans


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
