#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int mod = 1e9 + 7;
  int specialTriplets(vector<int> &nums) {
    unordered_map<int, int> umap1, umap2;
    for (int num : nums) {
      umap2[num]++;
    }
    int n = nums.size();
    int result = 0;
    umap2[nums[0]]--;
    for (int i = 1; i < n - 1; i++) {
      umap1[nums[i - 1]]++;
      umap2[nums[i]]--;
      result += umap1[2 * nums[i]] * umap2[2 * nums[i]];
      result = result % mod;
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {0, 1, 0, 0};
  int result = solution.specialTriplets(nums);
  std::cout << "result: " << result << std::endl;
}