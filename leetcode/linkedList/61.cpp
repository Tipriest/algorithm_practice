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
  int calLength(ListNode *head) {
    if (nullptr == head) {
      return 0;
    }
    return calLength(head->next) + 1;
  }
  ListNode *findtail(ListNode *node) {
    if (nullptr == node->next) {
      return node;
    }
    return findtail(node->next);
  }
  ListNode *rotateRight(ListNode *head, int k) {
    if(nullptr == head){
      return nullptr;
    }
    if(0 == k){
      return head;
    }
    //先计算一下整个链表的长度
    int n = calLength(head);
    k = k % n;
    k = n - k;
    if (n == k) {
      return head;
    }
    int count = 0;
    //找到第k个节点，让第k个节点指向空节点
    //把第k+1个节点存下来当作返回的头
    //把原来的头放到最后的尾巴上
    ListNode *newhead;
    ListNode *newtail;
    newtail = findtail(head);
    ListNode *cur = head;
    for (int i = 0; i < k; i++) {
      if ((k - 1) != i) {
        cur = cur->next;
      } else {
        //已经是k-1了
        newhead = cur->next;
        cur->next = nullptr;
        newtail->next = head;
      }
    }
    return newhead;
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
  ListNode *result = solution.rotateRight(head, 2);
  std::cout << "result: " << result << std::endl;
}