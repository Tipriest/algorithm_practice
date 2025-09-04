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
  const double EPS = 1e-6;
  bool dfs(vector<double> &cards) {
    int n = cards.size();
    if (1 == n) {
      return abs(cards[0] - 24) < EPS;
    }
    // 选两张牌 x=cards[i]和 y=cards[j]
    for (int i = 0; i < n; i++) {
      double x = cards[i];
      for (int j = i + 1; j < n; j++) {
        double y = cards[j];
        // 六种情况，加减乘除，其中减和除有不同的顺序
        vector<double> candidates = {x + y, x - y, y - x, x * y};
        if (abs(y) > EPS) { // 保证分母不为0
          candidates.push_back(x / y);
        } else if (abs(x) > EPS) { // 保证分母不为0
          candidates.push_back(y / x);
        }
        auto new_cards = cards;
        new_cards.erase(new_cards.begin() + j);
        for (double res : candidates) {
          new_cards[i] = res; //覆盖i
          static int count = 0;
          if (3 == new_cards.size()) {
            count++;
            std::cout << count << " ";
            for (int m = 0; m < new_cards.size(); m++) {
              std::cout << new_cards[m] << "  ";
            }
            std::cout << std::endl;
          }
        //   if (dfs(new_cards)) {
        //     return true;
        //   }
        }
      }
    }
    return false;
  }
  bool judgePoint24(vector<int> &cards) {
    vector<double> a(cards.begin(), cards.end());
    return dfs(a);
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 3, 4, 6};
  int result = solution.judgePoint24(nums);
  std::cout << "result: " << result << std::endl;
}