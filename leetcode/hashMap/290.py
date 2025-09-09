from typing import List
from queue import Queue
from collections import defaultdict
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        vs:list = s.split()
        uset1 = set(list(pattern))
        uset2 = set(vs)
        if len(vs) != len(pattern):
            return False
        if len(uset1) != len(uset2):
            return False
        umap = defaultdict(str)
        for i in range(len(pattern)):
            if not pattern[i] in umap:
                umap[pattern[i]] = vs[i]
            else:
                if umap[pattern[i]] != vs[i]:
                    return False
                else:
                    continue
        return True
        
if __name__ == "__main__":
    solution = Solution()
    pattern:str = "abba"
    s:str = "dog cat cat dog"
    result = solution.wordPattern(pattern, s)
    print(f"result = {result}")
 