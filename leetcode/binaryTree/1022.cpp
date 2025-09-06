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
  int dfs(TreeNode *cur, int res) {
    // 空节点
    if (nullptr == cur) {
      return 0;
    }

    // 叶子节点
    if (nullptr == cur->left && nullptr == cur->right) {
      if (0 == cur->val) {
        res = res << 1;
      } else {
        res = (res << 1) + 1;
      }
      return res;
    }

    // 非叶子节点
    if (0 == cur->val) {
      res = res << 1;
    } else {
      res = (res << 1) + 1;
    }
    return dfs(cur->left, res) + dfs(cur->right, res);
  }
  int sumRootToLeaf(TreeNode *root) { return dfs(root, 0); }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);
  int result = solution.sumRootToLeaf(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}