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
  TreeNode *inorder(TreeNode *root, TreeNode *p, bool& find) {
    if (nullptr == root) {
      return nullptr;
    }
    TreeNode *l = inorder(root->left, p, find);
    if (true == find) {
      find = false;
      return root;
    }
    if (p == root) {
      find = true;
    }
    TreeNode *r = inorder(root->right, p, find);
    if (!l && !r) {
      return nullptr;
    }
    if (!l) {
      return r;
    }
    return l;
  }
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    bool find = false;
    return inorder(root, p, find);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(2);
  TreeNode *n = new TreeNode(1);
  root->left = n;
  root->right = new TreeNode(3);

//   root->left->left = new TreeNode(1);
//   root->left->right = new TreeNode(1);
//   root->right->right = new TreeNode(1);
  TreeNode *result = solution.inorderSuccessor(root, n);
  std::cout << "result: " << result << std::endl;
  return 0;
}