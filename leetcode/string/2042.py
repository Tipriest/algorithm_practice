from typing import List
from queue import Queue


class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        s_l = s.split()
        last_num: int = -1
        for chs in s_l:
            if chs.isdigit():
                if int(chs) <= last_num:
                    return False
                else:
                    last_num = int(chs)
        return True


if __name__ == "__main__":
    solution = Solution()
    s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
    result = solution.areNumbersAscending(s)
    print(f"result = {result}")
