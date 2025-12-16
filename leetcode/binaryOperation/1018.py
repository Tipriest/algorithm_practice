from typing import List
from queue import Queue
class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = [False]*len(nums)
        x = 0
        for i, bit in enumerate(nums):
            x = (x << 1 | bit) % 5
            ans[i] = x == i
        return ans
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.prefixesDivBy5([0, 0, 1])
    print(f"result = {result}")
