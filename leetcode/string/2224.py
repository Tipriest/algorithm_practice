from typing import List
from queue import Queue
class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        current_l = current.split(':')
        correct_l = correct.split(':')
        current_l_sum = int(current_l[0])*60+int(current_l[1])
        correct_l_sum = int(correct_l[0])*60+int(correct_l[1])
        diff:int = correct_l_sum - current_l_sum
        minOperations:int = 0
        while(diff > 0):
            if diff >= 60:
                minOperations+=1
                diff -= 60
            elif diff >= 15:
                minOperations+=1
                diff -= 15
            elif diff >= 5:
                minOperations+=1
                diff -= 5
            elif diff >= 1:
                minOperations+=1
                diff -= 1
        return minOperations
if __name__ == "__main__":
    solution = Solution()
    current:str = "02:30"
    correct:str = "04:35"
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.convertTime(current, correct)
    print(f"result = {result}")
 