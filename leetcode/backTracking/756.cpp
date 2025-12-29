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
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    string groups[6][6]{};
    for (auto &s : allowed) {
      groups[s[0] - 'A'][s[1] - 'A'] += s[2];
    }
    int n = bottom.size();
    vector<string> pyramid(n);
    for (int i = 0; i < n - 1; i++) {
      pyramid[i].resize(i + 1);
    }
    pyramid[n - 1] = move(bottom);
    // 现在准备填(i, j)这个格子,
    // 从下往上填，每行从左往右填
    function<bool(int, int)> dfs;
    dfs = [&](int i, int j) -> bool {
      if (i < 0) { //所有格子都已经填完
        return true;
      }
      if (j == i + 1) {       // i 行已填完
        return dfs(i - 1, 0); // 开始填第i-1行
      }
      // 枚举i, j填什么字母
      // 这取决于 (i+1, j) 和 (i+1, j+1) 填的字母
      for (char top :
           groups[pyramid[i + 1][j] - 'A'][pyramid[i + 1][j + 1] - 'A']) {
        pyramid[i][j] = top;
        if (dfs(i, j + 1)) {
          return true;
        }
      }
      return false;
    };
    return dfs(n - 2, 0);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string bottom = "BCD";
  vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  bool result = solution.pyramidTransition(bottom, allowed);
  std::cout << "result: " << result << std::endl;
}