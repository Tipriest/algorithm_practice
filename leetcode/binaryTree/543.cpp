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
  int m = INT32_MIN;
  int calDepth(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    return max(calDepth(root->left), calDepth(root->right)) + 1;
  }
  int calLength(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    int lh = calDepth(root->left);
    int rh = calDepth(root->right);
    return lh + rh + 1;
  }
  int iter(TreeNode *cur) {
    if (nullptr == cur) {
      return 0;
    }
    m = max(m, calLength(cur));
    m = max(m, iter(cur->left));
    m = max(m, iter(cur->right));
    return m;
  }
  int diameterOfBinaryTree(TreeNode *root) { return iter(root)-1; }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(3);
  int result = solution.diameterOfBinaryTree(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}