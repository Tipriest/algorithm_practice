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
// 优化措施，把dfs里面关于左右子树的划分变成index，传入到下一层，而不是使用vector
class Solution {
public:
  bool verify(vector<int> &cur_series) {
    int n = cur_series.size();
    if (n < 3) {
      return true;
    }
    // >=3的情况就需要给cur_series进行分段了
    vector<vector<int>> split_series;
    split_series.push_back({cur_series[n - 1]});
    vector<int> temp;
    int stage = 0;
    for (int i = 0; i < n - 1; i++) {
      if (0 == stage && cur_series[i] <= split_series[0][0]) {
        temp.push_back(cur_series[i]);
      } else if (0 == stage && cur_series[i] > split_series[0][0]) {
        split_series.push_back(temp);
        temp.clear();
        temp.push_back(cur_series[i]);
        stage++;
      } else if (1 == stage && cur_series[i] <= split_series[0][0]) {
        return false;
      } else if (1 == stage && cur_series[i] > split_series[0][0]) {
        temp.push_back(cur_series[i]);
      }
      if (n - 2 == i) {
        split_series.push_back(temp);
        if (split_series.size() < 3) {
          split_series.push_back({});
        }
      }
      
    }
    return verify(split_series[1]) && verify(split_series[2]);
  }
  bool verifyTreeOrder(vector<int> &postorder) { return verify(postorder); }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 5, 10, 6, 9, 4, 3};
  bool result = solution.verifyTreeOrder(nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}