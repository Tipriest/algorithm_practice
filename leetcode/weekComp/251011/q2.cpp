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
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    vector<bool> isFibonacci(n, false);
    for (int i = 2; i < n; i++) {
      if (nums[i - 2] + nums[i - 1] == nums[i]) {
        isFibonacci[i] = true;
      }
    }
    int m_cons = 0;
    int temp_cons = 0;
    for (int i = 1; i < n; i++) {
      if (isFibonacci[i - 1] == true && isFibonacci[i] == true) {
        temp_cons++;
        m_cons = max(m_cons, temp_cons);
      } else if (isFibonacci[i - 1] == true && isFibonacci[i] == false) {
        m_cons = max(m_cons, temp_cons);
        temp_cons = 0;
      } else if (isFibonacci[i - 1] == false && isFibonacci[i] == true) {
        temp_cons++;
        m_cons = max(m_cons, temp_cons);
      } else if (isFibonacci[i - 1] == false && isFibonacci[i] == false) {
        temp_cons = 0;
      }
    }
    return m_cons + 2;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 1, 1, 1, 2, 3, 5, 1};
  int result = solution.longestSubarray(nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}