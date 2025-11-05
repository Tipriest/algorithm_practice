from typing import List
from queue import Queue



class Solution:
    def maximum69Number(self, num: int) -> int:
        num_s:list = list(str(num))
        
        for i, ch in enumerate(num_s):
            if ch == '6':
                num_s[i] = '9'
                break
        return int(''.join(num_s))
        
        
        
        
if __name__ == "__main__":
    solution = Solution()
    result = solution.maximum69Number(9669)
    print(f"result = {result}")
 