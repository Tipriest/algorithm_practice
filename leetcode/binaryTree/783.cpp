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
  vector<int> s;
  void backtracking(TreeNode *cur) {
    if (nullptr == cur) {
      return;
    }
    s.push_back(cur->val);
    backtracking(cur->left);
    backtracking(cur->right);
  }
  int minDiffInBST(TreeNode *root) {
    int mindiff = INT32_MAX;
    backtracking(root);
    int n = s.size();
    sort(s.begin(), s.end());
    for (int i = 1; i < n; i++) {
      mindiff = min(mindiff, s[i] - s[i - 1]);
    }
    return mindiff;
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
  bool result = solution.minDiffInBST(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}