from typing import List
from queue import Queue
from collections import defaultdict


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        umap = defaultdict(int)
        for num in arr:
            umap[num] += 1
        uset = set()
        for k, v in umap.items():
            if v in uset:
                return False
            else:
                uset.add(v)
        return True


if __name__ == "__main__":
    solution = Solution()
    nums: List[int] = [1, 2, 2, 1, 1, 3]
    result = solution.uniqueOccurrences(nums)
    print(f"result = {result}")
