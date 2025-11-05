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
  vector<int> fs1, fs2;
  void extractfs(TreeNode *cur, vector<int> &fs) {
    if (nullptr == cur) {
      return;
    }
    extractfs(cur->left, fs);
    if (nullptr == cur->left && nullptr == cur->right) {
      fs.push_back(cur->val);
    }
    extractfs(cur->right, fs);
  }
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    extractfs(root1, fs1);
    extractfs(root2, fs2);
    if(fs1.size() != fs2.size()){
      return false;
    }
    int n = fs1.size();
    for(int i = 0; i < n; i++){
      if(fs1[i] != fs2[i]){
        return false;
      }
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(8);

  TreeNode *root2 = new TreeNode(3);
  root2->left = new TreeNode(5);
  root2->right = new TreeNode(1);
  root2->left->left = new TreeNode(6);
  root2->left->right = new TreeNode(2);
  root2->left->right->left = new TreeNode(7);
  root2->left->right->right = new TreeNode(4);
  root2->right = new TreeNode(1);
  root2->right->left = new TreeNode(9);
  root2->right->right = new TreeNode(8);
  bool result = solution.leafSimilar(root, root2);
  std::cout << "result: " << result << std::endl;
  return 0;
}