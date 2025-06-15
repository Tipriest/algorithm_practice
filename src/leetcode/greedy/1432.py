from typing import List
from queue import Queue
class Solution:
    def maxDiff(self, num: int) -> int:
      num_l : list = list(str(num))
      max_v : int = 0
      min_v : int = 0
      max_conv: str = '-1'
      min_conv:str  = '-1'
      min_to:str
      for index, ch in enumerate(num_l):
        if ch != '9':
          max_conv = ch
          break
      for index, ch in enumerate(num_l):
        if index == 0 and ch != '1':
          min_conv = ch
          min_to = '1'
          break
        elif ch != '1' and ch != '0':
          min_conv = ch
          min_to = '0'
          break
        
      max_v = int(''.join([ '9' if ch is max_conv else ch for ch in num_l]))
      min_v = int(''.join([ min_to if ch is min_conv else ch for ch in num_l]))
      return max_v - min_v
      
          
        
        
      
      
if __name__ == "__main__":
    solution = Solution()
    result = solution.maxDiff(1101057)
    print(f"result = {result}")
 