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
class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    int n = nums.size();
    auto calnewid = [n, &nums](int i) {
      if (0 == nums[i]) {
        return i;
      } else if (nums[i] > 0) {
        int new_id = i + nums[i];
        while (new_id >= n) {
          new_id -= n;
        }
        return new_id;
      } else if (nums[i] < 0) {
        int new_id = i - abs(nums[i]);
        while (new_id < 0) {
          new_id += n;
        }
        return new_id;
      }
      cout << "err" << endl;
      return 0;
    };
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
      int n_id = calnewid(i);
      result[i] = nums[n_id];
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, -2, 1, 1};
  auto result = solution.constructTransformedArray(nums);
  //    std::cout << "result: " << result << std::endl;
}