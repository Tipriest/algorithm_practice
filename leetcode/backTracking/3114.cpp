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
  vector<string> possible_times;
  void backTracking(string &s, int n) {
    if (5 == n) {
      possible_times.push_back(s);
      return;
    }
    if (2 == n) {
      backTracking(s, n + 1);
      return;
    }
    if ('?' != s[n]) {
      backTracking(s, n + 1);
      return;
    }
    // 需要处理的情况
    if (0 == n) {
      for (int i = 0; i < 2; i++) {
        s[n] = '0' + i;
        backTracking(s, n + 1);
      }
      s[n] = '?';
    } else if (1 == n) {
      if ('0' == s[0]) {
        for (int i = 0; i < 10; i++) {
          s[n] = '0' + i;
          backTracking(s, n + 1);
        }
        s[n] = '?';
      } else {
        for (int i = 0; i < 2; i++) {
          s[n] = '0' + i;
          backTracking(s, n + 1);
        }
        s[n] = '?';
      }
    } else if (3 == n) {
      for (int i = 0; i < 6; i++) {
        s[n] = '0' + i;
        backTracking(s, n + 1);
      }
      s[n] = '?';
    } else if (4 == n) {
      for (int i = 0; i < 10; i++) {
        s[n] = '0' + i;
        backTracking(s, n + 1);
      }
      s[n] = '?';
    }
    
  }
  string findLatestTime(string s) {
    backTracking(s, 0);
    int t = -1;
    string last_time;
    for (string possible_time : possible_times) {
      int t_temp = stoi(possible_time.substr(0, 2)) * 60 +
                   stoi(possible_time.substr(3, 2));
      if(t_temp >= 12*60){
        continue;
      }
      if (t_temp > t) {
        last_time = possible_time;
        t = t_temp;
      }
    }
    return last_time;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "1?:?4";
  string result = solution.findLatestTime(s);
  std::cout << "result: " << result << std::endl;
}