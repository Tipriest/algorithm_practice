#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
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
  int minDeletionSize(vector<string> &strs) {
    int n = strs.size(), m = strs[0].size();
    vector<string> a(n); //最终得到的字符串数组
    int result = 0;
    for (int j = 0; j < m; j++) {
      bool del = false;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] + strs[i][j] > a[i + 1] + strs[i + 1][j]) {
          // j 列不是升序，必须要删除
          result++;
          del = true;
          break;
        }
      }
      if (!del) {
        // j列是升序，不删更好
        for (int i = 0; i < n; i++) {
          a[i] += strs[i][j];
        }
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<string> nums = {"xga", "xfb", "yfa"};
  int result = solution.minDeletionSize(nums);
  std::cout << "result: " << result << std::endl;
}