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
  int maximumPopulation(vector<vector<int>> &logs) {
    vector<int> psum(101, 0);
    int n = logs.size();
    for (int i = 0; i < n; i++) {
      psum[logs[i][0] - 1950]++;
      psum[logs[i][1] - 1950]--;
    }
    int max_v = -1;
    int max_y = -1;
    int tr = 0;
    for (int i = 0; i < psum.size(); i++) {
      tr += psum[i];
      if (tr > max_v) {
        max_v = tr;
        max_y = i + 1950;
      }
    }
    return max_y;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
  int result = solution.maximumPopulation(nums);
  std::cout << "result: " << result << std::endl;
}