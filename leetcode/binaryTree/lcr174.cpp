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
  priority_queue<int, vector<int>, greater<int>> pque;
  void dfs(TreeNode* cur, int cnt){
    if(nullptr == cur){
      return;
    }
    if(pque.size() < cnt){
      pque.push(cur->val);
    }else if(pque.top() < cur -> val){
      pque.push(cur->val);
      pque.pop();
    }
    dfs(cur->left, cnt);
    dfs(cur->right, cnt);
    return;
  }
  int findTargetNode(TreeNode *root, int cnt) {
    dfs(root, cnt);
    return pque.top();
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(9);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(5);
  int result = solution.findTargetNode(root, 2);
  std::cout << "result: " << result << std::endl;
}