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
  int countMatches(vector<vector<string>> &items, int ruleKey,
                   string ruleValue) {
    int n = items.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      if (ruleValue == items[i][ruleKey]) {
        result++;
      }
    }
    return result;
  }
  int countMatches(vector<vector<string>> &items, string ruleKey,
                   string ruleValue) {
    if (ruleKey == "type") {
      return countMatches(items, 0, ruleValue);
    } else if (ruleKey == "color") {
      return countMatches(items, 1, ruleValue);
    } else if (ruleKey == "name") {
      return countMatches(items, 2, ruleValue);
    }
    return 0;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<string>> nums = {{"phone", "blue", "pixel"},
                                 {"computer", "silver", "lenovo"},
                                 {"phone", "gold", "iphone"}};
  int result = solution.countMatches(nums, "color", "silver");
  std::cout << "result: " << result << std::endl;
}