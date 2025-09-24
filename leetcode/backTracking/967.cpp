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
  string digit;
  vector<int> digits;
  void dfs(int n, int k) {
    if (n == digit.size()) {
      digits.push_back(stoi(digit));
      return;
    }
    for (int i = 0; i < 10; i++) {
      if (0 == digit.size() && 0 == i) {
        continue;
      } else if (0 == digit.size()) {
        digit += to_string(i);
        dfs(n, k);
        digit.pop_back();
        continue;
      }
      // 说明这个时候size都大于0了，前面有一个值了
      if (k == abs((digit.back() - '0') - i)) {
        digit += to_string(i);
        dfs(n, k);
        digit.pop_back();
      }
    }
  }
  vector<int> numsSameConsecDiff(int n, int k) {
    dfs(n, k);
    return digits;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  vector<int> result = solution.numsSameConsecDiff(3, 7);
  // std::cout << "result: " << result << std::endl;
  return 0;
}