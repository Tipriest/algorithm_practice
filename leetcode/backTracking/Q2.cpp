#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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

class Solution {
public:
  int backtracking(vector<int> &nums, int left, int right) {
    int n = right - left;
    if (n == 1) {
      if (nums[left] == 0) {
        return 0;
      } else {
        return 1;
      }
    }
    int min_value = *min_element(nums.begin() + left, nums.begin() + right);
    int add_value = min_value == 0 ? 0 : 1;
    int total_value = add_value;
    int wl = left;
    for (int wr = left; wr < right; wr++) {
      if (nums[wr] == min_value) {
        if (wl == wr) {
          wl++;
          continue;
        } else {
          total_value += backtracking(nums, wl, wr);
          wl = wr + 1;
        }
      } else if (wr == right-1) {
        total_value += backtracking(nums, wl, wr+1);
      }
    }
    return total_value;
  }
  int minOperations(vector<int> &nums) {
    vector<int> new_nums;
    int n = nums.size();
    new_nums.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[i - 1]) {
        new_nums.push_back(nums[i]);
      }
    }

    return backtracking(new_nums, 0, new_nums.size());
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 4, 5};
  int result = solution.minOperations(nums);
  std::cout << "result: " << result << std::endl;
}