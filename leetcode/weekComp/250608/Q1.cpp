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
  bool canMakeEqual(vector<int> &nums, int k) {
    int n = nums.size();
    int result_p1 = 0, result_n1 = 0;
    vector<int> nums2 = nums;
    for(int i = 0; i < n-1; i++){
        if(nums[i] == 1){
            // result_p1不变
        }else if(nums[i] == -1){
            result_p1 ++;
            nums[i+1] = - nums[i+1];
        }
    }
    if(nums[n-1] == 1 && result_p1 <= k){
        return true;
    }
    for (int i = 0; i < n - 1; i++) {
      if (nums2[i] == 1) {
        result_n1++;
        nums2[i + 1] = -nums2[i + 1];
      } else if (nums2[i] == -1) {
        // result_n1不变
      }
    }
    if (nums2[n - 1] == -1 && result_n1 <= k) {
      return true;
    }
    return false;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, -1, 1};
  int result = solution.canMakeEqual(nums, 2);
  std::cout << "result: " << result << std::endl;
}