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
  bool checkZeroOnes(string s) {
    int maxOneNum = 0, maxZeroNum = 0;
    int n = s.size();
    int count = 0;
    if (s[0] == '0') {
      count++;
      maxZeroNum = max(maxZeroNum, count);
    } else {
      count++;
      maxOneNum = max(maxOneNum, count);
    }
    for (int i = 1; i < n; i++) {
      if (s[i] == '0' && s[i - 1] == '0') {
        count++;
        maxZeroNum = max(maxZeroNum, count);
      } else if (s[i] == '0' && s[i - 1] == '1') {
        count = 1;
        maxZeroNum = max(maxZeroNum, count);
      } else if (s[i] == '1' && s[i - 1] == '1') {
        count++;
        maxOneNum = max(maxOneNum, count);
      } else if (s[i] == '1' && s[i - 1] == '0') {
        count = 1;
        maxOneNum = max(maxOneNum, count);
      }
    }
    return maxOneNum > maxZeroNum;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "110100010";
  int result = solution.checkZeroOnes(s);
  std::cout << "result: " << result << std::endl;
}