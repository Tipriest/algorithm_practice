#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> treeNodes;
    treeNodes.push(root);
    int max_num = INT32_MIN;
    int max_row_id = -1;
    int cur_row_id = 1;
    while (!treeNodes.empty()) {
      // n 这一层的节点数量
      int n = treeNodes.size();

      int ans = 0;
      for (int i = 0; i < n; i++) {
        ans += treeNodes.front()->val;
        if (nullptr != treeNodes.front()->left) {
          treeNodes.push(treeNodes.front()->left);
        }
        if (nullptr != treeNodes.front()->right) {
          treeNodes.push(treeNodes.front()->right);
        }
        treeNodes.pop();
      }
      if (ans > max_num) {
        max_num = ans;
        max_row_id = cur_row_id;
      }
      cur_row_id++;
    }
    return max_row_id;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);
  int result = solution.maxLevelSum(root);
  std::cout << "result: " << result << std::endl;
}