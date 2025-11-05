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
  long long zeroFilledSubarray(vector<int> &nums) {
    long long result = 0;
    long long consecutive = 0;
    auto addfrom1tonum = [&]() { return (1 + consecutive) * consecutive / 2; };
    for (int num : nums) {
      if (0 == num) {
        consecutive++;
      } else {
        result += addfrom1tonum();
        consecutive = 0;
      }
    }
    result += addfrom1tonum();
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {0, 0, 0, 2, 0, 0};
  long long result = solution.zeroFilledSubarray(nums);
  std::cout << "result: " << result << std::endl;
}