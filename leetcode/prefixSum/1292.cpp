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
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        sum[i + 1][j + 1] =
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
      }
    }

    // 返回左上角在(r1,c1), 右下角在(r2,c2)的子矩阵元素和
    // 左上角(0,0), 右下角(1,1)
    auto query = [&](int r1, int c1, int r2, int c2) -> int {
      return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] +
             sum[r1][c1];
    };
    int ans = 0;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        while(i+ans < m && j + ans < n && query(i, j, i+ans, j+ans)<=threshold){
          ans++;
        }
      }
    }
    return ans;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> mat = {
      {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
  int threshold = 4;
  int result = solution.maxSideLength(mat, threshold);
  std::cout << "result: " << result << std::endl;
}