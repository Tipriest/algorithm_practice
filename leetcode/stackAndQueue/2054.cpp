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
  int maxTwoEvents(vector<vector<int>> &events) {
    // 按照结束时间排序
    sort(events.begin(), events.end(),
         [](vector<int> &e1, vector<int> &e2) { return e1[1] < e2[1]; });

    //从栈底到栈顶, 结束时间递增，价值递增
    vector<pair<int, int>> st = {{0, 0}}; //栈底哨兵
    // 枚举所有的event来填栈
    int ans = 0;
    for (vector<int> e : events) {
      int start_time = e[0], value = e[2];
      // 二分法查找最后一个结束时间小于start_time的活动
      auto it =
          --ranges::lower_bound(st, start_time, {}, &pair<int, int>::first);
      ans = max(ans, it->second + value);
      //   遇到比栈顶更大的，入栈
      if (value > st.back().second) {
        st.emplace_back(e[1], value);
      }
    }
    return ans;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
  int result = solution.maxTwoEvents(nums);
  std::cout << "result: " << result << std::endl;
}