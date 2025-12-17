from typing import List
from queue import Queue


class Solution:
    possible_times: list = []

    def backTracking(self, s: list, n: int):
        if 5 == n:
            self.possible_times.append("".join(s))
            return
        if 2 == n:
            self.backTracking(s, n + 1)
            return
        if "?" != s[n]:
            self.backTracking(s, n + 1)
            return
        if 0 == n:
            for i in range(2):
                s[n] = str(i)
                self.backTracking(s, n + 1)
            s[n] = "?"
        elif 1 == n:
            if "0" == s[0]:
                for i in range(10):
                    s[n] = str(i)
                    self.backTracking(s, n + 1)
                s[n] = "?"
            else:
                for i in range(2):
                    s[n] = str(i)
                    self.backTracking(s, n + 1)
                s[n] = "?"
        elif 3 == n:
            for i in range(6):
                s[n] = str(i)
                self.backTracking(s, n + 1)
            s[n] = "?"
        elif 4 == n:
            for i in range(10):
                s[n] = str(i)
                self.backTracking(s, n + 1)
            s[n] = "?"

    def findLatestTime(self, s: str) -> str:
        self.possible_times.clear()
        self.backTracking(list(s), 0)
        t: int = -1
        last_time: str = ""
        for possible_time in self.possible_times:
            temp: int = int(possible_time[0:2]) * 60 + int(possible_time[3:])
            if temp >= 12 * 60:
                continue
            if temp > t:
                last_time = possible_time
                t = temp
        return last_time


if __name__ == "__main__":
    solution = Solution()
    s: str = "0?:5?"
    result = solution.findLatestTime(s)
    print(f"result = {result}")
