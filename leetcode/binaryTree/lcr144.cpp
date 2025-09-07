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
  void flip(TreeNode *root) {
    if (nullptr == root->left && nullptr == root->right) {
      return;
    }
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (nullptr != root->left) {
      flip(root->left);
    }
    if (nullptr != root->right) {
      flip(root->right);
    }
  }
  TreeNode *flipTree(TreeNode *root) {
    if (nullptr == root) {
      return nullptr;
    }
    flip(root);
    return root;
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
  TreeNode *result = solution.flipTree(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}