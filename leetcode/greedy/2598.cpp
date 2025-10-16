#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
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
  int findSmallestInteger(vector<int> &nums, int value) {
    for (int num : nums) {
      int t = num % value;
      if (t < 0) {
        t += value;
      }
      m[t]++;
    }
    int t = 0;
    while (true) {
      int temp = t % value;
      if (m[temp] > 0) {
        m[temp]--;
      } else {
        return t;
      }
      t++;
    }
    return t;
  }
  unordered_map<int, int> m;
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 0, 3, 2, 4, 2, 1, 1, 0, 4};
  int value = 5;
  int result = solution.findSmallestInteger(nums, value);
  std::cout << "result: " << result << std::endl;
  return 0;
}