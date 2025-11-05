from collections import defaultdict
from typing import List
from queue import Queue
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans = left = 0
        map = defaultdict(int)
        for right, in_ in enumerate(fruits):
            map[in_] += 1
            while(len(map) > 2):
                map[fruits[left]] -= 1
                if map[fruits[left]] == 0:
                    del map[fruits[left]]
                left += 1
            ans = max(ans, right - left + 1)
        return ans
        
if __name__ == "__main__":
    solution = Solution()
    nums = [1, 2, 1]
    result = solution.totalFruit(nums)
    print(f"result = {result}")
 