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
constexpr int MX = 100'001;
int divisor_num[MX];
int divisor_sum[MX];
int init = [] {
  for (int i = 1; i < MX; i++) {
    for (int j = i; j < MX; j += i) { //枚举i的倍数j
      divisor_num[j]++;
      divisor_sum[j] += i;
    }
  }
  return 0;
}();
class Solution {
public:
  int sumFourDivisors(vector<int> &nums) {
    int ans = 0;
    for(int x: nums){
        if(4 == divisor_num[x]){
            ans += divisor_sum[x];
        }
    }
    return ans;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.sumFourDivisors(nums);
  std::cout << "result: " << result << std::endl;
}