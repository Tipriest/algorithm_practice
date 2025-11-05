#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
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
  int minMaxGame(vector<int> &nums) {
    int n = nums.size();
    if(1 == n){
      return nums[0];
    }
    vector<int> nums_new;
    for (int i = 0; i < n / 2; i++) {
      if (0 == i % 2) {
        nums_new.push_back(min(nums[2 * i], nums[2 * i + 1]));
      }else{
        nums_new.push_back(max(nums[2 * i], nums[2 * i + 1]));
      }
    }
    return minMaxGame(nums_new);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 3, 5, 2, 4, 8, 2, 2};
  int result = solution.minMaxGame(nums);
  std::cout << "result: " << result << std::endl;
}