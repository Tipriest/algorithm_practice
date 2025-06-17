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
  bool checkEqualPartitions(vector<int> &nums, long long target) {
    double total_sum = 1;
    for (int num : nums) {
      total_sum = total_sum * (double)num;
    }
    if (total_sum != (double)target * (double)target) {
      return false;
    }
    sort(nums.begin(), nums.end());
    // 初始化
    vector<vector<long long>> cur_sum;
    if(nums[0] == target){
        return true;
    }
    cur_sum.push_back({nums[0]});


    vector<long long> this_floor;
    for (int i = 1; i < nums.size(); i++) {
      this_floor.push_back(nums[i]);
      if (nums[0] == target) {
        return true;
      }
      for (int j = 0; j < cur_sum[i - 1].size(); j++) {
        this_floor.push_back(cur_sum[i - 1][j]);
        long long res_a = cur_sum[i-1][j]*nums[i];
        if (res_a == target) {
          return true;
        }else{
          this_floor.push_back(res_a);
        }
      }
      cur_sum.push_back(this_floor);
      this_floor.clear();
    }
    return false;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 1, 6, 8, 4};
  bool result = solution.checkEqualPartitions(nums, 24);
  std::cout << "result: " << result << std::endl;
}