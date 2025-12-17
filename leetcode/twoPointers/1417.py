from typing import List
from queue import Queue


class Solution:
    def reformat(self, s: str) -> str:
        l1: List[str] = []
        l2: List[str] = []
        for ch in s:
            if ch >= "0" and ch <= "9":
                l1.append(ch)
            else:
                l2.append(ch)
        if abs(len(l1) - len(l2)) > 1:
            return ""
        ls: List[str] = []
        ll: List[str] = []
        if len(l1) < len(l2):
            ls = l1
            ll = l2
        else:
            ls = l2
            ll = l1
        result: list = []
        while 0 != len(ll) or 0 != len(ls):
            if 0 != len(ll):
                result.append(ll[0])
                ll.remove(ll[0])
            if 0 != len(ls):
                result.append(ls[0])
                ls.remove(ls[0])
        return "".join(result)


if __name__ == "__main__":
    solution = Solution()
    s: str = "covid2019"
    result = solution.reformat(s)
    print(f"result = {result}")
