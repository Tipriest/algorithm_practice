#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
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
class Solution_0 {
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    unordered_set<int> uset(nums.begin(), nums.end());
    ListNode *new_head = nullptr, *new_cur = nullptr;
    ListNode *cur = head;
    while (nullptr != cur) {
      if (uset.count(cur->val)) {
        cur = cur->next;
      } else {
        if (nullptr == new_head) {
          new_head = new ListNode(cur->val);
          new_cur = new_head;
          cur = cur->next;
        } else {
          new_cur->next = new ListNode(cur->val);
          new_cur = new_cur->next;
          cur = cur->next;
        }
      }
    }
    return new_head;
  }
};
class Solution {
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    // 遍历现在的node,不是直接跳过，是的话来进行处理
    // 是的话首先判断给出去的result_head是否非空, 空的话把当前节点指定为result_head
    // 非空的话把result_cur的下一个节点变成这个节点, 然后把result_cur向后推一位

    unordered_set<int> uset(nums.begin(), nums.end());
    ListNode *new_head = nullptr, *new_cur = nullptr;
    ListNode *cur = head;
    while (nullptr != cur) {
      if (uset.count(cur->val)) {
        cur = cur->next;
      } else {
        if (nullptr == new_head) {
          new_head = cur;
          new_cur = cur;
          cur = cur->next;
        } else {
          new_cur->next = cur;
          new_cur = new_cur->next;
          cur = cur->next;
        }
      }
    }
    new_cur->next = nullptr;
    return new_head;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(1);
  head->next->next->next->next->next->next = new ListNode(2);

  vector<int> nums = {1, 2, 3};

  ListNode *result = solution.modifiedList(nums, head);
  std::cout << "result: " << result << std::endl;
  return 0;
}