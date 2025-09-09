from typing import List
from queue import Queue
class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        res:int = 0
        for operation in operations:
            if operation[0] == '-' or operation[2] == '-':
                res -= 1
            else:
                res += 1
        return res
if __name__ == "__main__":
    solution = Solution()
    operations =["--X","X++","X++"]
    result = solution.finalValueAfterOperations(operations)
    print(f"result = {result}")
 