from typing import List
from queue import Queue
from typing import Union

EPS = 1e-9


class Solution:
    def judgePoint24(self, cards: List[Union[int, float]]) -> bool:
        n = len(cards)
        if 1 == n:
            return abs(cards[0] - 24) < EPS

        # 选两张牌 x=cards[i]和y=cards[j]
        for i, x in enumerate(cards):
            for j in range(i + 1, n):
                y: float = cards[j]
                candidates: List = [x + y, x - y, y - x, x * y]
                if abs(y) > EPS:
                    candidates.append(x / y)
                if abs(x) > EPS:
                    candidates.append(y / x)
                new_cards = cards[:j] + cards[j + 1 :]
                for res in candidates:
                    new_cards[i] = res
                    if self.judgePoint24(new_cards):
                        return True
        return False


if __name__ == "__main__":
    solution = Solution()
    grid = [4, 1, 8, 7.0]
    result = solution.judgePoint24(grid)
    print(f"result = {result}")
