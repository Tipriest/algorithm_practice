#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
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
  int rob(TreeNode *root) {
    vector<int> result = robTree(root);
    return max(result[0], result[1]);
  }
  vector<int> robTree(TreeNode *cur) {
    // 返回值, 不偷cur, 偷cur,
    if (NULL == cur) {
      return {0, 0};
    }
    vector<int> left = robTree(cur->left);
    vector<int> right = robTree(cur->right);
    int val1 = cur->val + left[0] + right[0];
    int val2 = max(left[0], left[1]) + max(right[0], right[1]);
    return {val2, val1};
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    int result = solution.rob(10);
    std::cout << "result: " << result << std::endl;
}