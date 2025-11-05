from typing import List
from queue import Queue
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        key_map = {"type": 0, "color": 1, "name": 2}
        idx = key_map[ruleKey]
        result = 0
        for item in items:
            if item[idx] == ruleValue:
                result += 1
        return result

if __name__ == "__main__":
    solution = Solution()
    items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]]
    ruleKey = "color"
    ruleValue = "silver"
    result = solution.countMatches(items, ruleKey, ruleValue)
    print(f"result = {result}")
 