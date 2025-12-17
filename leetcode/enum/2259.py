from typing import List
from queue import Queue


class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        n = len(number)
        res = ""
        for i in range(n):
            if number[i] == digit:
                temp: str = number[:i] + number[i + 1 :]
                res = max(res, temp)
        return res


if __name__ == "__main__":
    solution = Solution()
    number: str = "123"
    digit: str = "3"
    result = solution.removeDigit(number, digit)
    print(f"result = {result}")
