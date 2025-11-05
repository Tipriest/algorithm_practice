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
  bool canBeValid(string s, string locked) {
    if (0 != s.size() % 2) {
      return false;
    }
    unordered_set<int> possible_results;
    possible_results.insert(0);
    for (int i = 0; i < s.size(); i++) {
      unordered_set<int> possible_results_temp;
      if (locked[i] == '0') {
        for (int possible_result : possible_results) {
          if (possible_result - 1 >= 0) {
            possible_results_temp.insert(possible_result - 1);
          }
          possible_results_temp.insert(possible_result + 1);
        }
      } else if (locked[i] == '1') {
        if (s[i] == '(') {
          for (int possible_result : possible_results) {
            possible_results_temp.insert(possible_result + 1);
          }
        } else if (s[i] == ')') {
          for (int possible_result : possible_results) {
            if (possible_result - 1 >= 0) {
              possible_results_temp.insert(possible_result - 1);
            }
          }
        }
      }
      possible_results = possible_results_temp;
      if (0 == possible_results.size()) {
        return false;
      }
    }
    if (possible_results.find(0) != possible_results.end()){
      return true;
    }
    return false;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.canBeValid("))()))", "010100");
  std::cout << "result: " << result << std::endl;
}