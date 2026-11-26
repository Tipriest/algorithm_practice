#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
  bool canAliceWin(int n) {
    int num_of_times = 0;
    int should_remove = 10;
    while (n >= should_remove) {
      n -= should_remove;
      should_remove--;
      num_of_times++;
    }
    return 0 != num_of_times%2;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  int n = 12;
  bool result = solution.canAliceWin(n);
  std::cout << "result: " << result << std::endl;
}