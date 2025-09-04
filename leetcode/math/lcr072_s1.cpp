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
  // 袖珍计算器法
  int mySqrt(int x) {
    // sqrt(x) = exp(0.5*ln(x))
    if (0 == x) {
      return 0;
    }
    int res = exp(0.5 * log(x));
    if (pow(res + 1, 2) <= x) {
      return res + 1;
    }
    return res;
  }
  // 袖珍计算器法
  double mySqrt(int x, int n) {
    // sqrt(x) = exp(0.5*ln(x))
    if (0 == x) {
      return 0;
    }
    double res = exp(0.5 * log(x));
    if (pow(res + 1, 2) <= x) {
      return res + 1;
    }
    //不是四舍五入，是直接舍弃掉后面的
    res = (int)(res * pow(10, n)) / pow(10, n);
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  double result = solution.mySqrt(5, 5);
  std::cout << "result: " << result << std::endl;
}