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
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int q = queries.size();
    int left = -1, right = q + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      (checkOK(getDiff(nums, queries, mid)) ? right : left) = mid;
    }
    return right <= q ? right : -1;
  }
  vector<int> getDiff(vector<int> &nums, vector<vector<int>> &queries, int k) {
    int n = nums.size();
    vector<int> diff(n, 0);
    diff[0] = nums[0];
    for (int i = 1; i < n; i++) {
      diff[i] = nums[i] - nums[i - 1];
    }
    for (int i = 0; i < k; i++) {
      vector<int> query = queries[i];
      diff[query[0]] -= query[2];
      if (query[1] + 1 < n)
        diff[query[1] + 1] += query[2];
    }
    return diff;
  }
  bool checkOK(vector<int> diff) {
    int n = diff.size();
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        diff[i] += diff[i - 1];
      }
      if (diff[i] > 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {2, 0, 2};
  vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
  int result = solution.minZeroArray(nums, queries);
  std::cout << "result: " << result << std::endl;
}