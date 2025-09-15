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
// 优化建议，改一个queue试一试
class Solution {
public:
  bool dfs(const vector<TreeNode *> &nodes, bool even) {
    if (0 == nodes.size()) {
      return true;
    }
    vector<TreeNode *> next_nodes;
    int last_val = even ? INT32_MIN : INT32_MAX;

    for (TreeNode *node : nodes) {
      if (node->left) {
        next_nodes.push_back(node->left);
      }
      if (node->right) {
        next_nodes.push_back(node->right);
      }
      if (even) {
        if (1 != node->val % 2) {
          return false;
        }
        if (node->val <= last_val) {
          return false;
        }
      } else {
        if (0 != node->val % 2) {
          return false;
        }
        if (node->val >= last_val) {
          return false;
        }
      }
      last_val = node->val;
    }
    return dfs(next_nodes, !even);
  }
  bool isEvenOddTree(TreeNode *root) {
    vector<TreeNode *> nodes = {root};
    return dfs(nodes, true);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->right = new TreeNode(1);
  bool result = solution.isEvenOddTree(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}