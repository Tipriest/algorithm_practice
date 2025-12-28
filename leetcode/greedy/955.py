from typing import List
from queue import Queue


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n: int = len(strs)
        m: int = len(strs[0])
        a: List[str] = [''] * n
        res: int = 0
        for j in range(m):
            for i in range(n - 1):
                if a[i + 1] + strs[i + 1][j] < a[i] + strs[i][j]:
                    res += 1
                    break
            else:
                for i, s in enumerate(strs):
                    a[i] += s[j]
        return res


if __name__ == "__main__":
    solution = Solution()
    strs = ["xga", "xfb", "yfa"]
    result = solution.minDeletionSize(strs)
    print(f"result = {result}")
