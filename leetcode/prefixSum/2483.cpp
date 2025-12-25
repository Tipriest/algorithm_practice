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
  int bestClosingTime(string customers) {
    int n = customers.size();
    int left_y = 0, left_n = 0;
    int total_y = 0, total_n = 0;
    for (int i = 0; i < n; i++) {
      if ('Y' == customers[i]) {
        total_y++;
      } else {
        total_n++;
      }
    }
    int cost = INT32_MAX;
    // 在第i时刻关门的代价
    for(int i = 0; i < n; i++){
        cost = min(cost, total_n - left_n);
        if(customers[i] == 'Y'){
            left_y++;
        }else{
            left_n++;
        }
    }
    // 在第n时刻关门，也即一直不关门的代价
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string customers = "YYNY";
  int result = solution.bestClosingTime(customers);
  std::cout << "result: " << result << std::endl;
}