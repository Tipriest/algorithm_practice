#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <numeric>
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
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    int max_id = 0, max_num = 0;
    for (int i = 0; i < mat.size(); i++) {
      int sum = std::accumulate(mat[i].begin(), mat[i].end(), 0);
      if(sum > max_num){
        max_id = i;
        max_num = sum;
      }
    }
    return {max_id, max_num};
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> nums = {{0, 1}, {1, 0}};
  vector<int> result = solution.rowAndMaximumOnes(nums);
  std::cout << "result[0]: " << result[0] << "   result[1]: " << result[1]
            << std::endl;
}