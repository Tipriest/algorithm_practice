#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  long long maximumProduct(vector<int> &nums, int m) {
    int n = nums.size();
    long long result = LONG_LONG_MIN;
    int left_max = INT_MIN, left_min = INT_MAX;
    for (int i = m - 1; i < n; i++) {
      left_max = max(left_max, nums[i - (m - 1)]);
      left_min = min(left_min, nums[i - (m - 1)]);
      long long temp = nums[i] * left_max > nums[i] * left_min
                           ? nums[i] * left_max
                           : nums[i] * left_min;
      result = result > temp ? result : temp;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {10, 9, 3, 6, 6, 2, -7, -6, -6};
  int result = solution.maximumProduct(nums, 7);
  std::cout << "result: " << result << std::endl;
}