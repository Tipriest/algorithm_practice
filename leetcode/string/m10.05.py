from typing import List
from queue import Queue
class Solution:
    def findString(self, words: List[str], s: str) -> int:
        l, r = 0, len(words)-1
        while l <= r:
            m = l + (r-l)//2
            # 暂存一下m的位置，后面将移动m寻找非空串，失败的话需要用m_t恢复
            m_t = m
            while words[m] == '' and m < r:
                m += 1
            # 这种情况说明了m_t右边全都是''
            if words[m] == '':
                r = m_t -1
                continue
            else:
                if s == words[m]:
                    return m
                elif s < words[m]:
                    r = m - 1
                else:
                    l = m + 1
        return -1
if __name__ == "__main__":
    solution = Solution()
    words = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]
    s = "ta"
    result = solution.findString(words, s)
    print(f"result = {result}")
 