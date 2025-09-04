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
  string concatHex36(int n) {
    int n2 = pow(n, 2);
    int n3 = pow(n, 3);
    string result;
    while (n3 != 0) {
      int temp = n3 % 36;
      n3 = n3 / 36;
      if (temp < 10) {
        result += char('0' + temp);
      } else {
        result += char('A' + temp - 10);
      }
    }
    while (n2 != 0) {
      int temp = n2 % 16;
      n2 = n2 / 16;
      if (temp < 10) {
        result += char('0' + temp);
      } else {
        result += char('A' + temp - 10);
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string result = solution.concatHex36(13);
  std::cout << "result: " << result << std::endl;
}