from typing import List
from queue import Queue


class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        n: int = len(nums)
        isEven: bool = True
        j: int = 1
        for i in range(0, n, 2):
            if 1 == nums[i] % 2:
                while 1 == nums[j] % 2:
                    j += 2
                nums[i], nums[j] = nums[j], nums[i]
        return nums


if __name__ == "__main__":
    solution = Solution()
    nums = [4, 2, 5, 7]
    result = solution.sortArrayByParityII(nums)
    print(f"result = {result}")
