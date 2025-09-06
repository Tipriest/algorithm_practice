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
  set<int> s;
  void dfs(vector<TreeNode *> &nodes) {
    if (0 == nodes.size()) {
      return;
    }
    vector<TreeNode *> new_nodes;
    for (auto node : nodes) {
      s.insert(node->val);
      if (nullptr != node->left) {
        new_nodes.push_back(node->left);
        new_nodes.push_back(node->right);
      }
    }
    return dfs(new_nodes);
  }
  int findSecondMinimumValue(TreeNode *root) {
    vector<TreeNode *> nodes = {root};
    dfs(nodes);
    if (s.size() >= 2) {
      return *std::next(s.begin());
    }
    return -1;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);
  int result = solution.findSecondMinimumValue(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}