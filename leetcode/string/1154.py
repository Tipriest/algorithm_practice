from typing import List
from queue import Queue
class Solution:
    def dayOfYear(self, date: str) -> int:
        leapyear = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        nonleapyar = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        date_l = date.split('-')
        year:int = int(date_l[0])
        month:int = int(date_l[1])
        day:int = int(date_l[2])
        isleapyear:bool = False
        if year % 4 == 0:
            if 0 == year % 400:
                isleapyear = True
            elif 0 == year % 100:
                isleapyear = False
            else:
                isleapyear = True
        dayUsed:int = 0
        for i in range(month-1):
            if isleapyear:
                dayUsed += leapyear[i]
            else:
                dayUsed += nonleapyar[i]
        dayUsed += day
        return dayUsed
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.dayOfYear("1900-05-02")
    print(f"result = {result}")
 