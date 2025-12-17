from typing import List
from queue import Queue


class Solution:
    def countDigits(self, num: int) -> int:
        def getNums(num: int) -> List[int]:
            result: List[int] = []
            while 0 != num:
                result.append(num % 10)
                num //= 10
            return result

        res: int = 0
        results: List[int] = getNums(num)
        for result in results:
            if 0 == num % result:
                res += 1
        return res


if __name__ == "__main__":
    solution = Solution()
    grid = [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ]
    result = solution.countDigits(1248)
    print(f"result = {result}")
