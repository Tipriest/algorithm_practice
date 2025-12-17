from typing import List
from queue import Queue


class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        st: list = []
        result: List[str] = []
        n: int = len(word)
        i: int = 0
        meet: bool = False
        for i in range(n):
            if ch != word[i]:
                st.append(word[i])
            else:
                st.append(word[i])
                i += 1
                meet = True
                break
        if meet:
            while not 0 == len(st):
                result.append(st[-1])
                st.pop()
            for m in range(i, n):
                result.append(word[m])
            return "".join(result)
        else:
            return word
        return word


if __name__ == "__main__":
    solution = Solution()
    word: str = "abcdefd"
    ch: str = "d"
    result = solution.reversePrefix(word, ch)
    print(f"result = {result}")
