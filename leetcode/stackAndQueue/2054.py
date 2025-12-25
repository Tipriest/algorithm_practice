from typing import List
from queue import Queue
from functools import cache
from bisect import bisect_left


class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # 按照结束时间进行排序
        events.sort(key=lambda e: e[1])

        # 从栈底到栈顶, 结束时间递增, 价值递增
        st = [(0, 0)]  # 栈底哨兵
        ans = 0
        for start_time, end_time, value in events:
            # 二分查找最后一个结束时间小于start_time的活动
            i = bisect_left(st, (start_time,)) - 1
            ans = max(ans, st[i][1] + value)
            # 遇到比栈顶更大的价值，入栈
            if value > st[-1][1]:
                st.append((end_time, value))
        return ans


if __name__ == "__main__":
    solution = Solution()
    nums = [[1, 3, 2], [4, 5, 2], [2, 4, 3]]
    result = solution.maxTwoEvents(nums)
    print(f"result = {result}")
