from typing import List
from queue import Queue
from functools import cache


class Solution1:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp: List[int] = [1] * n
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[j] + 1, dp[i])
        return max(dp)


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int) -> int:
            res = 0
            for j in range(i):
                if nums[j] < nums[i]:
                    res = max(res, dfs(j))
            return res + 1  # 加一提到循环外面

        return max(dfs(i) for i in range(len(nums)))


if __name__ == "__main__":
    solution = Solution()
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    result = solution.lengthOfLIS(nums)
    print(f"result = {result}")
