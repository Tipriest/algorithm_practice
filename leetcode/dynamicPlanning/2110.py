from typing import List
from queue import Queue


class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n: int = len(prices)
        dp: int = 1
        res: int = 1
        for i in range(1, n):
            if prices[i] == prices[i - 1] - 1:
                dp += 1
            else:
                dp = 1
            res += dp
        return res


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    nums = [1, 2, 3]
    result = solution.getDescentPeriods(nums)
    print(f"result = {result}")
