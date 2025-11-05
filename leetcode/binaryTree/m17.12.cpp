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
  vector<int> v;
  TreeNode *findLeftest(TreeNode *cur) {
    while (nullptr != cur->left) {
      cur = cur->left;
    }
    return cur;
  }
  void iter(TreeNode *cur) {
    if (nullptr == cur) {
      return;
    }
    iter(cur->left);
    v.push_back(cur->val);
    iter(cur->right);
  }
  TreeNode *convertBiNode(TreeNode *root) {
    if (nullptr == root) {
      return nullptr;
    }
    TreeNode *temp = findLeftest(root);
    iter(root);
    int n = v.size();
    TreeNode *cur = temp;
    for (int i = 1; i < n; i++) {
      cur->right = new TreeNode(v[i]);
      cur = cur->right;
    }
    return temp;
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
  TreeNode *result = solution.convertBiNode(root);
  // std::cout << "result: " << result << std::endl;
  return 0;
}