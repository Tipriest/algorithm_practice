from typing import List
from queue import Queue


class Solution:
    def isValidSudoku(self, boards: List[List[str]]) -> bool:
        uset: List[str] = []
        for board in boards:
            for ch in board:
                if "." == ch:
                    continue
                else:
                    if ch in uset:
                        return False
                    else:
                        uset.append(ch)
            uset.clear()
        n: int = len(boards)
        for j in range(n):
            for i in range(n):
                if "." == boards[i][j]:
                    continue
                else:
                    if boards[i][j] in uset:
                        return False
                    else:
                        uset.append(boards[i][j])
            uset.clear()
        n = len(boards) // 3
        for i in range(n):
            for j in range(n):
                for x in range(3):
                    for y in range(3):
                        if "." == boards[3 * i + x][3 * j + y]:
                            continue
                        else:
                            if boards[3 * i + x][3 * j + y] in uset:
                                return False
                            else:
                                uset.append(boards[3 * i + x][3 * j + y])
                uset.clear()
        return True


if __name__ == "__main__":
    solution = Solution()
    boards = [
        [".", ".", ".", ".", ".", ".", "5", ".", "."],
        [".", ".", ".", ".", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", ".", ".", ".", "3"],
        [".", "2", ".", "7", ".", ".", ".", ".", "."],
        ["8", "3", "6", "5", ".", ".", ".", ".", "1"],
        [".", ".", ".", ".", ".", "1", ".", ".", "."],
        ["2", ".", ".", ".", ".", ".", ".", ".", "5"],
        [".", ".", ".", ".", ".", ".", ".", ".", "7"],
        [".", ".", ".", "4", ".", ".", ".", "7", "."],
    ]
    result = solution.isValidSudoku(boards)
    print(f"result = {result}")
