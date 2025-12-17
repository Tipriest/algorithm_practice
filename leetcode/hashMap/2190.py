from typing import List
from queue import Queue
from collections import defaultdict


class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        umap = defaultdict(int)
        n: int = len(nums)
        for i in range(0, n - 1):
            if key == nums[i]:
                umap[nums[i + 1]] += 1
        max_num: int = -1
        target: int = 0
        for num, count in umap.items():
            if count > max_num:
                target = num
                max_num = count
        return target


if __name__ == "__main__":
    solution = Solution()
    nums: list = [1, 100, 200, 1, 100]
    result = solution.mostFrequent(nums, 1)
    print(f"result = {result}")
