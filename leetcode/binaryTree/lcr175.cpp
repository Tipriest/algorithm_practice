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
  int bfs(const vector<TreeNode *> &cls) {
    if (0 == cls.size()) {
      return 0;
    }
    vector<TreeNode *> ncls;
    for (TreeNode *cl : cls) {
      if (nullptr != cl->left) {
        ncls.push_back(cl->left);
      }
      if (nullptr != cl->right) {
        ncls.push_back(cl->right);
      }
    }
    return bfs(ncls) + 1;
  }
  int calculateDepth(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    vector<TreeNode *> cls = {root};
    return bfs(cls);
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
  int result = solution.calculateDepth(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}