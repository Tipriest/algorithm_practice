from typing import List
from queue import Queue


class Solution:
    def splitWordsBySeparator(
        self, words: List[str], separator: str
    ) -> List[str]:
        result: List[str] = []
        for word in words:
            word_splits = word.split(separator)
            for word_split in word_splits:
                if word_split:
                    result.append(word_split)
        return result


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    result = solution.splitWordsBySeparator(["$easy$", "$problem$"], "$")
    print(f"result = {result}")
