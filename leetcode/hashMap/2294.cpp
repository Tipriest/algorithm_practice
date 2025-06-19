#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    ranges::sort(nums);
    int ans = 1;
    int rec = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] - rec > k) {
        ans++;
        rec = nums[i];
      }
    }
    return ans;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 1, 3, 4, 2};
  int result = solution.partitionArray(nums, 0);
  std::cout << "result: " << result << std::endl;
}