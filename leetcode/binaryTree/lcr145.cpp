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
  bool check(TreeNode *r1, TreeNode *r2) {
    if (nullptr == r1 && nullptr == r2) {
      return true;
    }
    if (nullptr == r1 || nullptr == r2) {
      return false;
    }
    if (r1->val != r2->val) {
      return false;
    }
    return check(r1->left, r2->right) && check(r1->right, r2->left);
  }
  bool checkSymmetricTree(TreeNode *root) {
    if(nullptr ==root){
      return true;
    }
    return check(root->left, root->right);
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
  bool result = solution.checkSymmetricTree(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}