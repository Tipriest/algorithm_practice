from typing import List
from queue import Queue
class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        uset = set()
        for num in nums1:
            uset.add(num)
        for num in nums2:
            if num in uset:
                return num
        return -1        
if __name__ == "__main__":
    solution = Solution()
    nums1 = [1, 2, 3, 6]
    nums2 = [2, 3, 4, 5]
    result = solution.getCommon(nums1, nums2)
    print(f"result = {result}")
 