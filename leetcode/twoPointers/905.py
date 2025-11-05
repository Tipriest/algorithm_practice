from typing import List
from queue import Queue
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        n:int = len(nums)
        i:int = 0
        j:int = n-1
        while i < j:
            if 1 == nums[i]%2:
                nums[i], nums[j] = nums[j], nums[i]
                j -= 1
            else:
                i += 1
        return nums
if __name__ == "__main__":
    solution = Solution()
    nums = [3, 1, 2, 4]
    result = solution.sortArrayByParity(nums)
    print(f"result = {result}")