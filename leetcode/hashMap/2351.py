from typing import List
from queue import Queue
from collections import defaultdict
class Solution:
    def repeatedCharacter(self, s: str) -> str:
        umap = defaultdict(int)
        for ch in s:
            umap[ch] +=1
            if 2 == umap[ch]:
                return ch
        return 'a'
if __name__ == "__main__":
    solution = Solution()
    s:str = "abccbaacz"
    result = solution.repeatedCharacter(s)
    print(f"result = {result}")
 