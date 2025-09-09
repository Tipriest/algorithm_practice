from typing import List
from queue import Queue
class Solution:
    def minMaxDifference(self, num: int) -> int:
        num_s: str = str(num)
        max_change_value: int = 0
        min_change_value: int = 0
        
        def change_ch(num : str, change_value_from : int, change_value_to: int) -> int:
            num_list = list(num)
            for i in range(len(num_list)):
                if num_list[i] == str(change_value_from):
                    num_list[i] = str(change_value_to)
            return int(''.join(num_list))

        for ch in num_s:
            if ch == '9':
                continue
            max_change_value = ch
            break
        for ch in num_s:
            if ch == '0':
                continue
            min_change_value = ch
            break
        
            
        return change_ch(str(num), max_change_value, 9) - change_ch(str(num), min_change_value, 0)
    
    
if __name__ == "__main__":
    solution = Solution()
    grid = [['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']]
    result = solution.minMaxDifference(11891)
    print(f"result = {result}")
 