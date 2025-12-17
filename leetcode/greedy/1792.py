from typing import List
from queue import Queue
from heapq import heapify
from heapq import heapreplace


class Entry:
    __slots__ = "p", "t"

    def __init__(self, p: int, t: int):
        self.p = p
        self.t = t

    def __lt__(self, b: "Entry") -> bool:
        return (self.t - self.p) * (b.t + 1) * b.t > (b.t - b.p) * (
            self.t + 1
        ) * self.t


class Solution:
    def maxAverageRatio(
        self, classes: List[List[int]], extraStudents: int
    ) -> float:
        h = [Entry(*c) for c in classes]
        heapify(h)
        for _ in range(extraStudents):
            heapreplace(h, Entry(h[0].p + 1, h[0].t + 1))
        return sum(e.p / e.t for e in h) / len(h)


if __name__ == "__main__":
    solution = Solution()

    classes = [[1, 2], [3, 5], [2, 2]]
    result = solution.maxAverageRatio(classes, 2)
    print(f"result = {result}")
