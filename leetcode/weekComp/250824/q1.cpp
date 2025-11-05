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
  int gcdOfOddEvenSums(int n) {
    int sumOdd = n * (1 + 2 * n - 1) / 2;
    int sumEven = n * (1 + 2 * n - 1) / 2 + n;
    int max_gcd = min(sumOdd, sumEven);
    while (true) {
      if (sumEven % max_gcd == 0 && sumOdd % max_gcd == 0) {
        return max_gcd;
      } else {
        max_gcd--;
      }
    }
    return 0;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.gcdOfOddEvenSums(5);
  std::cout << "result: " << result << std::endl;
}