#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> subarraySum(vector<int> &arr, int target) {
    if (target == 0) {
      return {-1};
    }
    // code here
    // 用一个左闭右闭的滑动窗口
    int left = 0, right = 0;
    int cur_sum = arr[0];
    while (cur_sum != target) {
      if (cur_sum > target) {
        // 只有一个数
        if (left == right) {
          left++;
          right++;
          if (right < arr.size()) {
            cur_sum = arr[right];
          } else {
            return {-1};
          }

        } else { //现在不止一个数
          cur_sum -= arr[left];
          left++;
          
        }
      } else if (cur_sum < target) {
        right++;
        if (right < arr.size()) {
          cur_sum += arr[right];
        } else {
          return {-1};
        }
      }
    }
    return {left + 1, right + 1};
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 3, 7, 5};
  int target = 12;
  vector<int> result = solution.subarraySum(nums, target);
  std::cout << "result[0]: " << result[0] << "result[1]: " << result[1]
            << std::endl;
}