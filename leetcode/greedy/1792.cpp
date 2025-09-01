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
  struct Ratio {
    int pass, total;
    bool operator<(const Ratio &oth) const {
      return (long)(oth.total + 1) * oth.total * (total - pass) <
             (long)(total + 1) * total * (oth.total - oth.pass);
    }
  };
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue<Ratio> q;
    for (auto &c : classes) {
      q.push({c[0], c[1]});
    }
    for(int i = 0; i < extraStudents; i++){
      auto [pass, total] = q.top();
      q.pop();
      q.push({pass+1, total+1});
    }
    double res = 0;
    while(!q.empty()){
      auto [pass, total] = q.top();
      q.pop();
      res += 1.0*pass/total;
    }
    return res/classes.size();
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
  double result = solution.maxAverageRatio(classes, 2);
  std::cout << "result: " << result << std::endl;
}