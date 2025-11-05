#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <queue>
#include <vector>
#include <functional> //包含std::greater 和 std::less
#include <math.h>
#include <limits.h>
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
  int myAtoi(string s) {
    int n = s.size();
    int l = 0, r = 0;
    bool pos = true;
    bool meet_pos = false;
    for (; l < n; l++) {
      if (!meet_pos && s[l] == ' ') {
        continue;
      } else if (!meet_pos && s[l] == '+') {
        meet_pos = true;
        continue;
      } else if (!meet_pos && s[l] == '-') {
        meet_pos = true;
        pos = false;
        continue;
      } else if (s[l] >= '0' && s[l] <= '9') {
        //现在的这个l开始是第一个数字字符了
        break;
      } else {
        //第一个遇到的是非数字字符，归0退出
        return 0;
      }
    }
    r = l;
    string res;
    // 这里要处理前导零的事情
    bool meet_zero = false;
    for (; r < n; r++) {
      if (s[r] >= '0' && s[r] <= '9') {
        if (!meet_zero && '0' == s[r]) {
          continue;
        }
        res += s[r];
        meet_zero = true;
      } else {
        break;
      }
    }
    if (res.size() > 10) {
      return pos ? INT32_MAX : INT32_MIN;
    } else if (0 == res.size()) {
      return 0;
    }
    long resl = (long)(pos ? 1 : -1) * stol(res);
    if (resl >= INT32_MAX) {
      return INT32_MAX;
    } else if (resl <= INT32_MIN) {
      return INT32_MIN;
    }
    return (pos ? 1 : -1) * stoi(res);
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {7, 1, 5, 3, 6, 4};
   int result = solution.myAtoi("-2147483648");
   std::cout << "result: " << result << std::endl;
   return 0;
}