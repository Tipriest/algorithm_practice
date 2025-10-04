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
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (!((tolower(s[l]) >= 'a' && tolower(s[l] <= 'z')) ||
               s[l] >= '0' && s[l] <= '9')) {
        l++;
        if (l > s.size()) {
          return true;
        }
      }
      while (!((tolower(s[r]) >= 'a' && tolower(s[r] <= 'z')) ||
               s[r] >= '0' && s[r] <= '9')) {
        r--;
        if (r < 0) {
          return true;
        }
      }
      if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }
      l++, r--;
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "A man, a plan, a canal: Panama";
  int result = solution.isPalindrome(s);
  std::cout << "result: " << result << std::endl;
}