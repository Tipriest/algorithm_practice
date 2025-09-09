#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
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
  int x, y;
  bool bfs(vector<TreeNode *> &ls) {
    if (0 == ls.size()) {
      return false;
    }
    vector<TreeNode *> nls;
    set<int> vs;
    for (auto l : ls) {
      vs.insert(l->val);
      if (nullptr != l->left) {
        nls.push_back(l->left);
      }
      if (nullptr != l->right) {
        nls.push_back(l->right);
      }
      if (nullptr != l->left && nullptr != l->right) {
        if (x == l->left->val && y == l->right->val) {
          return false;
        } else if (y == l->left->val && x == l->right->val) {
          return false;
        }
      }
    }
    if (vs.find(x) != vs.end() && vs.find(y) != vs.end()) {
      return true;
    } else if (vs.find(x) != vs.end() || vs.find(y) != vs.end()) {
      return false;
    }
    return bfs(nls);
  }
  bool isCousins(TreeNode *root, int _x, int _y) {
    this->x = _x;
    this->y = _y;
    vector<TreeNode *> ls = {root};
    return bfs(ls);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  bool result = solution.isCousins(root, 4, 3);
  std::cout << "result: " << result << std::endl;
  return 0;
}