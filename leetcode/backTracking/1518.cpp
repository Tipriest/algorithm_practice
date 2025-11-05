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
  int bt(int filled, int empty, int numExchange) {
    if (filled + empty >= numExchange) {
      return filled + (filled + empty) / numExchange +
             bt(0,
                (filled + empty) / numExchange + (filled + empty) % numExchange,
                numExchange);
    } else {
      return filled;
    }
  }
  int numWaterBottles(int numBottles, int numExchange) {
    return bt(numBottles, 0, numExchange);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.numWaterBottles(9, 3);
  std::cout << "result: " << result << std::endl;
  return 0;
}