#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
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
  int minPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int min_sum = INT32_MIN;
    for(int i = 0; i < n/2; i++){
        min_sum = max(min_sum, nums[i]+nums[n-1-i]);
    }
    return min_sum;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 5, 2, 3};
  int result = solution.minPairSum(nums);
  std::cout << "result: " << result << std::endl;
}