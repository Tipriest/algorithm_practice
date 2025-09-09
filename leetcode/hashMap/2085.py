from typing import List
from queue import Queue
from collections import Counter
class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        c1 = Counter(words1)
        c2 = Counter(words2)
        res = 0
        for item in c1:
            if(1 == c1[item] and 1 == c2[item]):
                res+=1
        return res
        
        
        
if __name__ == "__main__":
    solution = Solution()
    words1 = ["leetcode","is","amazing","as","is"]
    words2 = ["amazing","leetcode","is"]
    result = solution.countWords(words1, words2)
    print(f"result = {result}")
 