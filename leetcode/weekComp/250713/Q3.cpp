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
  char processStr(string s, long long k) {
    k = k + 1;
    int n = 0;
    for (char ch : s) {
      if (ch == '*') {
        if (n > 0) {
          n -= 1;
        }
      } else if (ch == '#') {
        n *= 2;
      } else if (ch == '%') {
      } else {
        n += 1;
      }
    }
    int op_idx = s.size()-1;
    while(n != k || !(s[op_idx] >='a'&&s[op_idx]<='z') ){
      if (op_idx == '*') {
        if (n > 0) {
          n -= 1;
        }
      } else if (op_idx == '#') {
        n *= 2;
      } else if (op_idx == '%') {
      } else {
        n += 1;
      }
    }



  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "a#b%*";
  long long k = 1;
  char result = solution.processStr(s, k);
  std::cout << "result: " << result << std::endl;
}