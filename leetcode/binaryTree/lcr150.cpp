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
  vector<vector<int>> res;
  void bfs(vector<TreeNode *> &ls) {
    if (0 == ls.size()) {
      return;
    }
    vector<TreeNode *> nls;
    vector<int> nls_v;
    for (TreeNode *l : ls) {
      if (nullptr != l->left) {
        nls.push_back(l->left);
        nls_v.push_back(l->left->val);
      }
      if (nullptr != l->right) {
        nls.push_back(l->right);
        nls_v.push_back(l->right->val);
      }
    }
    if (nls_v.size() > 0) {
      res.push_back(nls_v);
    }
    bfs(nls);
  }
  vector<vector<int>> decorateRecord(TreeNode *root) {
    if (nullptr == root) {
      return {};
    }
    res.push_back({root->val});
    vector<TreeNode *> ls = {root};
    bfs(ls);
    return res;
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
  vector<vector<int>> result = solution.decorateRecord(root);
  // std::cout << "result: " << result << std::endl;
  return 0;
}