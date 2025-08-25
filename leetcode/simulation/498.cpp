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
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    vector<int> result;
    int m = mat.size();
    int n = mat[0].size();
    bool reverse = false;
   //  所有对应左边竖着的地方出来的斜的条
    for (int i = 0; i < m; i++) {
      vector<int> temp;
      int x = i;
      int y = 0;
      while(x >= 0 && y < n){
         temp.push_back(mat[x][y]);
         x--;
         y++;
      }
      if(reverse){
         for(int i = 0; i < temp.size(); i++){
            result.push_back(temp[temp.size()-1-i]);
         }
      }else{
        for (int num : temp) {
          result.push_back(num);
        }
      }
      reverse = !reverse;
    }
   //  所有对应底下的地方出来的斜的条(排除第一个)
    for (int i = 1; i < n; i++) {
      vector<int> temp;
      int x = m-1;
      int y = i;
      while (x >= 0 && y < n) {
        temp.push_back(mat[x][y]);
        x--;
        y++;
      }
      if (reverse) {
        for (int i = 0; i < temp.size(); i++) {
          result.push_back(temp[temp.size() - 1 - i]);
        }
      } else {
        for (int num : temp) {
          result.push_back(num);
        }
      }
      reverse = !reverse;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> result = solution.findDiagonalOrder(mat);
  //   std::cout << "result: " << result << std::endl;
}