from typing import List
from queue import Queue


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total: int = sum(nums)
        temp: int = 0
        n: int = len(nums)
        for i in range(n):
            if temp * 2 == total - nums[i]:
                return i
            else:
                temp += nums[i]
        return -1


if __name__ == "__main__":
    solution = Solution()
    nums = [1, 7, 3, 6, 5, 6]
    result = solution.pivotIndex(nums)
    print(f"result = {result}")
