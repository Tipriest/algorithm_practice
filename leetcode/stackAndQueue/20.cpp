#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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
class Solution {
public:
  bool isValid(string s) {
    stack<char> st1;
    for (char ch : s) {
      if (ch == '(') {
        st1.push(')');
      } else if (ch == '[') {
        st1.push(']');
      } else if (ch == '{') {
        st1.push('}');
      } else if (0 == st1.size()) {
        return false;
      } else if (ch != st1.top()) {
        return false;
      }else{
        st1.pop();
      }
    }
    if (!st1.empty()) {
      return false;
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "([])";
  int result = solution.isValid(s);
  std::cout << "result: " << result << std::endl;
}