#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    set<int> result_set;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (key == nums[i]) {
        for (int j = -k; j <= k; j++) {
            int left = max(0, i - k);
            int right = min(i + k, n-1);
            for(int j = left; j <= right; j++){
                result_set.insert(j);
            }
        }
      }
    }
    return vector<int>(result_set.begin(), result_set.end());
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
  vector<int> result = solution.findKDistantIndices(nums, 9, 1);
  for (int res : result) {
    std::cout << res << " ";
  }
  std::cout << endl;
}