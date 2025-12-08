#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
  bool sqrttable(int n) {
    int sqrt_n = sqrt(n);
    return pow(sqrt_n, 2) == n;
  }
  int countTriples(int n) {
    int s_n = pow(n, 2);
    int res = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i; j < n; j++) {
        int temp = pow(i, 2) + pow(j, 2);
        if (temp > s_n) {
          break;
        } else if (!sqrttable(temp)) {
          continue;
        } else {
          res += 2;
        }
      }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  int result = solution.countTriples(10);
  std::cout << "result: " << result << std::endl;
}