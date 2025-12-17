from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next: Optional["ListNode"] = None


class Solution:
    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:
        visited = set()
        cur = headA
        while cur:
            visited.add(cur)
            cur = cur.next
        cur = headB
        while cur:
            if cur in visited:
                return cur
            cur = cur.next
        return None


if __name__ == "__main__":
    # 构造测试用例
    solution = Solution()
    # 公共部分
    common = ListNode(8)
    common.next = ListNode(4)
    common.next.next = ListNode(5)
    # headA: 4 -> 1 -> 8 -> 4 -> 5
    headA = ListNode(4)
    headA.next = ListNode(1)
    headA.next.next = common
    # headB: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    headB = ListNode(5)
    headB.next = ListNode(6)
    headB.next.next = ListNode(1)
    headB.next.next.next = common
    result = solution.getIntersectionNode(headA, headB)
    print(f"result = {result.val if result else None}")
