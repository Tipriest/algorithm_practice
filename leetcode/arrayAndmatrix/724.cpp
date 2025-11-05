#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <numeric> // for std::accumulate
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
  int pivotIndex(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int temp = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if ((sum - nums[i]) == temp * 2) {
        return i;
      } else {
        temp += nums[i];
      }
    }
    return -1;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  int result = solution.pivotIndex(nums);
  std::cout << "result: " << result << std::endl;
}