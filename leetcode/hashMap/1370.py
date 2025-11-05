from typing import List
from queue import Queue
from collections import defaultdict
class Solution:
    def sortString(self, s: str) -> str: 
        sl:list = [0 for i in range(26)]
        for ch in s:
            sl[ord(ch) - ord('a')] += 1
        ret:list = []
        while len(ret)<len(s):
            for i in range(26):
                if sl[i] > 0:
                    ret.append(chr(ord('a')+i))
                    sl[i]-=1
            for i in range(25, -1, -1):
                if sl[i] > 0:
                    ret.append(chr(ord('a')+i))
                    sl[i]-=1
        return "".join(ret)
if __name__ == "__main__":
    solution = Solution()
    s:str = "rat"
    result = solution.sortString(s)
    print(f"result = {result}")
 