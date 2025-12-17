from typing import List
from queue import Queue


class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        result: int = 0
        uset: set = set()
        for word in words:
            word_v: str = word[::-1]
            if word_v in uset:
                result += 1
                uset.remove(word_v)
            else:
                uset.add(word)
        return result


if __name__ == "__main__":
    solution = Solution()
    words: List[str] = [
        "tg",
        "gf",
        "oz",
        "nd",
        "ks",
        "fo",
        "ac",
        "gl",
        "gt",
        "fg",
    ]
    result = solution.maximumNumberOfStringPairs(words)
    print(f"result = {result}")
