#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
#include <ranges>
#include <queue>

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
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
    std::ranges::sort(queries, {}, [](auto &q) { return q[0]; });
    int n = nums.size();
    vector<int> diff(n + 1, 0);

    priority_queue<int> pq;
    int j = 0;
    int sum_diff = 0;
    for (int i = 0; i < n; i++) {
      // 将现在所有左端点小于等于i的都放进最大堆
      while (j < queries.size() && queries[j][0] <= i) {
        pq.push(queries[j][1]);
        j++;
      }
      while (sum_diff < nums[i] && pq.size() != 0 && pq.top() >= i) {
        sum_diff++;
        diff[pq.top() + 1]--;
        pq.pop();
      }
      if (sum_diff < nums[i]) {
        return -1;
      }
    }
    return pq.size();
  }
};

int main() {
    // 示例二叉树
    Solution solution;
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    int result = solution.maxRemoval(nums, queries);
    std::cout << "result: " << result << std::endl;
}