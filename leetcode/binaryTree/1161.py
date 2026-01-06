from typing import List, Optional
from queue import Queue
from functools import cache
from collections import defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        treeNodes = [root]
        max_num = float('-inf')
        max_row_id = -1
        cur_row_id = 1
        while treeNodes:
            tmp = treeNodes
            treeNodes = []
            ans = 0
            for node in tmp:
                ans += node.val
                if node.left:
                    treeNodes.append(node.left)
                if node.right:
                    treeNodes.append(node.right)
            if ans > max_num:
                max_num = ans
                max_row_id = cur_row_id
            cur_row_id+=1
        return max_row_id


if __name__ == "__main__":
    solution = Solution()
    root = TreeNode(1)
    root.left = TreeNode(7)
    root.right = TreeNode(0)
    root.left.left = TreeNode(7)
    root.left.right = TreeNode(-8)
    result = solution.maxLevelSum(root)
    print(f"result = {result}")
