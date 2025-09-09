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
  int findNumSum(int n) {
    int res = 0;
    while (0 != n) {
      res += n % 10;
      n /= 10;
    }
    return res;
  }
  int findNumMul(int n) {
    int res = 1;
    while (0 != n) {
      res *= n % 10;
      n /= 10;
    }
    return res;
  }
  bool checkDivisibility(int n) {
    int a = findNumSum(n);
    int b = findNumMul(n);
    if (0 == n % (a + b)) {
      return true;
    }
    return false;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.checkDivisibility(99);
  std::cout << "result: " << result << std::endl;
}