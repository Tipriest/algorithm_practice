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
  int calSum(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    return calSum(root->left) + calSum(root->right) + root->val;
  }
  int calTilt(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    return abs(calSum(root->left) - calSum(root->right));
  }
  int findTilt(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    int a = calTilt(root);
    int b = findTilt(root->left);
    int c = findTilt(root->right);
    return a+b+c;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(1);
  // root->left->left = new TreeNode(1);
  // root->left->right = new TreeNode(1);
  // root->right = new TreeNode(1);
  // root->right->right = new TreeNode(1);

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left = new TreeNode(3);
  root->left = new TreeNode(4);
  root->left = new TreeNode(5);

  // root->left->left = new TreeNode(1);
  // root->left->right = new TreeNode(1);
  // root->right->right = new TreeNode(1);
  bool result = solution.findTilt(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}