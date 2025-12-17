from typing import List
from queue import Queue


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        a1: List[str] = version1.split(".")
        a2: List[str] = version2.split(".")
        if len(a1) < len(a2):
            for _ in range(len(a2) - len(a1)):
                a1.append("0")
        elif len(a2) < len(a1):
            for i in range(len(a1) - len(a2)):
                a2.append("0")
        for i in range(len(a1)):
            if int(a1[i]) > int(a2[i]):
                return 1
            elif int(a1[i]) < int(a2[i]):
                return -1
        return 0


if __name__ == "__main__":
    solution = Solution()
    s1: str = "1.2.5.5"
    s2: str = "1.10"
    result = solution.compareVersion(s1, s2)
    print(f"result = {result}")
