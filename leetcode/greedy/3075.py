from typing import List
from queue import Queue
from functools import cache


class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        res = 0
        for i in range(k):
            res += happiness[i] - i if (happiness[i] - i) >= 0 else 0
        return res


if __name__ == "__main__":
    solution = Solution()
    nums = [12, 1, 42]
    k = 2
    result = solution.maximumHappinessSum(nums, k)
    print(f"result = {result}")
