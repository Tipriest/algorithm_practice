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
class Solution {
public:
  string processStr(string s) {
    string result;
    for (char ch : s) {
      if (ch == '*') {
        if (result.size() > 0) {
          result.erase(result.end()-1);
        }
      } else if (ch == '#') {
        result += result;
      } else if (ch == '%') {
        reverse(result.begin(), result.end());
      } else {
        result += ch;
      }
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "a#b%*";
  string result = solution.processStr(s);
  std::cout << "result: " << result << std::endl;
}