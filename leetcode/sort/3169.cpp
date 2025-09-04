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

class Solution {
public:
  int countDays(int days, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end(),
         [](const vector<int> &ma, const vector<int> &mb) {
           return ma[0] < mb[0];
         });
    int start_day = meetings[0][0];
    int end_day = meetings[0][1];
    int n = meetings.size();
    int result = start_day - 1;
    for (int i = 1; i < n; i++) {
      if (meetings[i][0] > end_day) {
        result += meetings[i][0] - end_day - 1;
        start_day = meetings[i][0];
        end_day = meetings[i][1];
      } else {
        if (meetings[i][1] <= end_day) {
          continue;
        } else {
          end_day = meetings[i][1];
        }
      }
    }
    result += days - end_day;
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{6, 11},  {7, 13}, {8, 9},  {5, 8},  {3, 13},
                              {11, 13}, {1, 3},  {5, 10}, {8, 13}, {3, 9}};
  int result = solution.countDays(14, nums);
  std::cout << "result: " << result << std::endl;
}