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
  int factorial(int n) {
    if (n < 1) {
      std::__throw_invalid_argument("invalid input");
    }
    if (n == 1) {
      return 1;
    }
    return n * factorial(n - 1);
  }
  int select(int n, int x) {
    if (n < x) {
      std::__throw_invalid_argument("invalid input");
    }
    if (n <= 0 || x < 0) {
      std::__throw_invalid_argument("invalid input");
    }
    if (0 == x) {
      return 1;
    }
    return factorial(n) / (factorial(x) * factorial(n - x));
  }
  int paintingPlan(int n, int target) {
    if (target == n * n) {
      return 1;
    } else if (target == 0) {
      return 1;
    }
    int res = 0;
    for (int x = 0; x < n; x++) {
      if (target - n * x < 0) {
        break;
      } else if (0 == (target - n * x) % (n - x)) {
        int y = (target - n * x) / (n - x);
        res += select(n, x) * select(n, y);
      } else {
        continue;
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.paintingPlan(4, 13);
  std::cout << "result: " << result << std::endl;
}