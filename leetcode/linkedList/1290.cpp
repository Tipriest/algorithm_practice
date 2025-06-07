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
  int getDecimalValue(ListNode *head) {
    int order = 0;
    int result = 0;
    ListNode *cur = head;
    while (cur != nullptr) {
      result *= 2;
      result += cur->val;
      order++;
      cur = cur->next;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(0);
  head->next->next = new ListNode(1);
  int result = solution.getDecimalValue(head);
  std::cout << "result: " << result << std::endl;
}