from typing import List
from queue import Queue


class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        uset = set()
        for i in range(26):
            uset.add(chr(ord("a") + i))
        for ch in sentence:
            if ch in uset:
                uset.discard(ch)
            else:
                continue
            if 0 == len(uset):
                return True
        return False


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    result = solution.checkIfPangram("leetcode")
    print(f"result = {result}")
