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
  int convertTime(string current, string correct) {
    int current_sum =
        stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
    int correct_sum =
        stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
    int diff = correct_sum - current_sum;
    int minOperations = 0;
    while (diff > 0) {
      if (diff >= 60) {
        minOperations += 1;
        diff -= 60;
      } else if (diff >= 15) {
        minOperations += 1;
        diff -= 15;
      } else if (diff >= 5) {
        minOperations += 1;
        diff -= 5;
      } else if (diff >= 1) {
        minOperations += 1;
        diff -= 1;
      }
    }
    return minOperations;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.convertTime("00:00", "23:59");
  std::cout << "result: " << result << std::endl;
}