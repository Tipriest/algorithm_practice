from typing import List
from queue import Queue


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        left: int = 0
        right: int = len(s) - 1
        while left < right:
            while not (
                (s[left] >= "a" and s[left] <= "z")
                or (s[left] >= "0" and s[left] <= "9")
            ):
                left += 1
                if left >= len(s):
                    return True
            while not (
                (s[right] >= "a" and s[right] <= "z")
                or (s[right] >= "0" and s[right] <= "9")
            ):
                right -= 1
                if right < 0:
                    return True
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True


if __name__ == "__main__":
    solution = Solution()
    s = ".,"
    result = solution.isPalindrome(s)
    print(f"result = {result}")
