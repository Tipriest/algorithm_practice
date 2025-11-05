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
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};
class Solution {
public:
  void bfs(Node *cur, vector<int> &vl) {
    if(nullptr == cur){
      return;
    }
    int n = cur->children.size();
    for(int i = 0; i < n; i++){
      bfs(cur->children[i], vl);
    }
    vl.push_back(cur->val);
    return;
  }
  vector<int> postorder(Node *root) {
    vector<int> res;
    bfs(root, res);
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  Node *root = new Node(1);
  vector<int> result = solution.postorder(root);
  // std::cout << "result: " << result << std::endl;
  return 0;
}