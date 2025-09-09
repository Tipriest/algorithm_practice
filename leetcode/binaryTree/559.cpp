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
  int dfs(vector<Node *> ls) {
    if (0 == ls.size()) {
      return 0;
    }
    vector<Node *> nls;
    for (int i = 0; i < ls.size(); i++) {
      for (int j = 0; j < ls[i]->children.size(); j++) {
        nls.push_back(ls[i]->children[j]);
      }
    }
    return dfs(nls) + 1;
  }
  int maxDepth(Node *root) {
    if (root = nullptr) {
      return 0;
    }
    return dfs({root});
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  Node *root = new Node(1);
  bool result = solution.maxDepth(root);
  std::cout << "result: " << result << std::endl;
  return 0;
}