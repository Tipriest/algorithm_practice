from typing import List
from queue import Queue
from collections import defaultdict
class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        umap = defaultdict(int)
        l:int = 0
        r:int = 0
        n:int = len(word)
        result:int = 0
        uset = set(['a', 'e', 'i', 'o', 'u'])
        for l in range(n):
            umap.clear()
            for r in range(l, n):
                if not word[r] in uset:
                    break
                else:
                    umap[word[r]]+=1
                    if umap['a'] and umap['e'] and umap['i'] and umap['o'] and umap['u']:
                        result+=1
                    else:
                        continue
        return result
if __name__ == "__main__":
    solution = Solution()
    s:str = "aeiouu"
    result = solution.countVowelSubstrings(s)
    print(f"result = {result}")
 