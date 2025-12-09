from typing import List
from queue import Queue

class Solution:
    MOD = 10 ** 9 + 7
    def specialTriplets(self, nums: List[int]) -> int:
        num_cnt = {}
        num_partial_cnt = {}
        for v in nums:
            num_cnt[v] = num_cnt.get(v, 0)+1
        ans = 0
        for v in nums:
            target = v * 2
            l_cnt = num_partial_cnt.get(target, 0)
            num_partial_cnt[v] = num_partial_cnt.get(v, 0)+1
            r_cnt = num_cnt.get(target, 0) - num_partial_cnt.get(target, 0)
            ans = (ans + l_cnt*r_cnt)%self.MOD
        return ans



if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.specialTriplets([10,5,10])
    print(f"result = {result}")
