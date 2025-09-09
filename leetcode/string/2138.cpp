#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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
  vector<string> divideString(string s, int k, char fill) {
    int n = s.size();
    vector<string> result;
    int idx = 0;
    while (n >= k) {
      result.push_back(s.substr(idx, k));
      n -= k;
      idx += k;
    }
    string ls = s.substr(idx, n);
    if (ls.size() == 0) {
      return result;
    }
    while (ls.size() < k) {
      ls += fill;
    }
    result.push_back(ls);
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "abcdefghi";
  vector<string> result = solution.divideString(s, 3, 'x');
  // std::cout << "result: " << result << std::endl;
}