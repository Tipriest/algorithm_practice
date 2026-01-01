from typing import List
from queue import Queue
from functools import cache
from collections import defaultdict
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        uset = set()
        for num in nums:
            if num in uset:
                return num
            else:
                uset.add(num)
        return 0
if __name__ == "__main__":
    solution = Solution()
    nums = [7, 1, 5, 3, 6, 4]
    result = solution.repeatedNTimes(nums)
    print(f"result = {result}")
