from typing import List
from queue import Queue


class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        s = set()
        s.add(arr[0])
        n = len(arr)
        for i in range(1, n):
            if arr[i] * 2 in s:
                return True
            elif 0 == arr[i] % 2 and arr[i] / 2 in s:
                return True
            else:
                s.add(arr[i])
        return False


if __name__ == "__main__":
    solution = Solution()
    nums = [0, -2, 2]
    result = solution.checkIfExist(nums)
    print(f"result = {result}")
