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
  int minimumOperations(vector<vector<int>> &grid) {
   int m = grid.size();
   int n = grid[0].size();
   int res = 0;
   for(int j = 0; j < n; j++){
      int curCol = 1, curLine = j;
      while(curCol < m){
        if (grid[curCol][j] < grid[curCol-1][j]+1){
          res += grid[curCol - 1][j] + 1 - grid[curCol][j];
          grid[curCol][j] = grid[curCol - 1][j] + 1;
          curCol++;
        }else{
          curCol++;
          continue;
        }
      }
   }
   return res;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<vector<int>> grid = {{3, 2}, {1, 3}, {3, 4}, {0, 1}};
   int result = solution.minimumOperations(grid);
   std::cout << "result: " << result << std::endl;
}