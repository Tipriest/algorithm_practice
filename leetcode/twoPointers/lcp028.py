from typing import List
from queue import Queue


class Solution:
    mod: int = int(1e9 + 7)

    def purchasePlans(self, nums: List[int], target: int) -> int:
        nums.sort()
        n: int = len(nums)
        l: int = 0
        r: int = n - 1
        res: int = 0
        while l < r:
            if nums[l] + nums[r] > target:
                r -= 1
            else:
                res += r - l
                res %= self.mod
                l += 1
        return res


if __name__ == "__main__":
    solution = Solution()
    nums: List[int] = [2, 5, 3, 5]
    result = solution.purchasePlans(nums, 6)
    print(f"result = {result}")
