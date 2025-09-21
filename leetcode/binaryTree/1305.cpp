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
  void inorder(TreeNode *root, vector<int> &result) {
    if (nullptr == root) {
      return;
    }
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
    return;
  }
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> sort1, sort2;
    inorder(root1, sort1);
    inorder(root2, sort2);
    int n = sort1.size(), m = sort2.size();
    int i = 0, j = 0;
    vector<int> res;
    while (i < n || j < m) {
      if (i < n && j < m) {
        if (sort1[i] < sort2[j]) {
          res.push_back(sort1[i]);
          i++;
        } else {
          res.push_back(sort2[j]);
          j++;
        }
      } else if (i < n) {
        res.push_back(sort1[i]);
        i++;
      } else if (j < m) {
        res.push_back(sort2[j]);
        j++;
      }
    }
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
  vector<int> result = solution.getAllElements(root, root);
  // std::cout << "result: " << result << std::endl;
  return 0;
}