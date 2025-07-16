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
  int maximumLength(vector<int> &nums) {
    vector<int> result(4, 0);
    bool odd_even = true;
    bool even_odd = true;
    for (int num : nums) {
      if (num % 2 == 0) {
        result[0]++;
        if (odd_even == false) {
          result[2]++;
          odd_even = !odd_even;
        }
        if (even_odd == true) {
          result[3]++;
          even_odd = !even_odd;
        }
      } else if (num % 2 == 1) {
        result[1]++;
        if (odd_even == true) {
          result[2]++;
          odd_even = !odd_even;
        }
        if (even_odd == false) {
          result[3]++;
          even_odd = !even_odd;
        }
      }
    }
    sort(result.begin(), result.end());
    return result[3];
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 1, 1, 2, 1, 2};
  int result = solution.maximumLength(nums);
  std::cout << "result: " << result << std::endl;
}