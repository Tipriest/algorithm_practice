from typing import List
from queue import Queue


class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n: int = len(nums)
        if 1 == n:
            return nums[0]
        nums_n: List[int] = []
        for i in range(n // 2):
            if 0 == i % 2:
                nums_n.append(min(nums[2 * i], nums[2 * i + 1]))
            else:
                nums_n.append(max(nums[2 * i], nums[2 * i + 1]))
        return self.minMaxGame(nums_n)


if __name__ == "__main__":
    solution = Solution()
    nums = [1, 3, 5, 2, 4, 8, 2, 2]
    result = solution.minMaxGame(nums)
    print(f"result = {result}")
