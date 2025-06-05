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
  int mod = 1e9 + 7;

public:
  int rangeSum(vector<int> &nums, int n, int left, int right) {
    priority_queue<int, vector<int>, std::less<int>> pq;
    int l = 0;
    int r = nums.size();
    for (int i = l; i < r; i++) {
      int ans = 0;
      for (int j = i; j < r; j++) { //左闭右闭
        ans += nums[j];
        if (pq.size() < right) {
          pq.push(ans);
        } else {
          if (pq.top() > ans) {
            pq.push(ans);
            pq.pop();
          } else {
            break;
          }
        }
      }
    }
    int result = 0;
    for (int i = 0; i <= right - left; i++) {
      result += pq.top();
      pq.pop();
      result = result % mod;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  int result = solution.rangeSum(nums, 4, 1, 5);
  std::cout << "result: " << result << std::endl;
}