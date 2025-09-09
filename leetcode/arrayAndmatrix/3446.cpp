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
  vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
   int m = grid.size();
   int n = grid[0].size();
   for(int i = 0; i < m; i++){
      int curCol = i, curLine = 0;
      priority_queue<int, vector<int>, less<int>> pq;
      while(curCol < m && curLine < n){
         pq.push(grid[curCol][curLine]);
         curCol++;
         curLine++;
      }
      curCol = i, curLine = 0;
      while(!pq.empty()){
        grid[curCol][curLine] = pq.top();
        pq.pop();
        curCol++;
        curLine++;
      }
   }
   for (int j = 1; j < n; j++) {
     int curCol = 0, curLine = j;
     priority_queue<int, vector<int>, greater<int>> pq;
     while (curCol < m && curLine < n) {
       pq.push(grid[curCol][curLine]);
       curCol++;
       curLine++;
     }
     curCol = 0, curLine = j;
     while (!pq.empty()) {
       grid[curCol][curLine] = pq.top();
       pq.pop();
       curCol++;
       curLine++;
     }
   }
   return grid;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
   vector<vector<int>> result = solution.sortMatrix(grid);
   // std::cout << "result: " << result << std::endl;
   return 0;
}