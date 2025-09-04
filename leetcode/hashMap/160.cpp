#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> umap;
    ListNode *cur = headA;
    while (nullptr != cur) {
      umap.insert(cur);
      cur = cur->next;
    }
    cur = headB;
    while (nullptr != cur) {
      if (umap.end() != umap.find(cur)) {
        return cur;
      }
      cur = cur->next;
    }
    return nullptr;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  ListNode *headA = new ListNode(), *headB = new ListNode(),
           *headC = new ListNode();
  headA->val = 4;
  headA->next = new ListNode(1);
  ListNode *common = new ListNode(8);
  headA->next->next = common;
  common->next = new ListNode(4);
  common->next->next = new ListNode(5);
  headB->val = 5;
  headB->next = new ListNode(6);
  headB->next->next = new ListNode(1);
  headB->next->next->next = common;
  solution.getIntersectionNode(headA, headB);
  //   std::cout << "result: " << result << std::endl;
}