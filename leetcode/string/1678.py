from typing import List
from queue import Queue
class Solution:
    def interpret(self, command: str) -> str:
        pattern_l:list = []
        result:list = []
        n:int = len(command)
        for i in range(n):
            pattern_l.append(command[i])
            pattern:str = "".join(pattern_l)
            if pattern == "G":
                result.append('G')
            elif pattern == "()":
                result.append('o')
            elif pattern == "(al)":
                result.append("al")
            else:
                continue
            pattern_l.clear()
        return "".join(result)
                
if __name__ == "__main__":
    solution = Solution()
    command:str = "(al)G(al)()()G"
    result = solution.interpret(command)
    print(f"result = {result}")
 