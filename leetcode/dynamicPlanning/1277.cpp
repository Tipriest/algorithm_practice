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
// // 用了一层k来表示数量，也可以不用，滚动更新
// class Solution {
// public:
//   int countSquares(vector<vector<int>> &matrix) {
//     int m = matrix.size(), n = matrix[0].size();
//     int k_max = min(m, n) + 1;
//     vector<vector<vector<bool>>> dp(
//         m, vector<vector<bool>>(n, vector<bool>(k_max, false)));
//     int result = 0;
//     for (int i = 0; i < m; i++) {
//       for (int j = 0; j < n; j++) {
//         if (matrix[i][j] == true) {
//           dp[i][j][1] = true;
//           result++;
//         }
//       }
//     }
//     for (int k = 2; k <= k_max; k++) {
//       for (int i = 0; i + 1 < m; i++) {
//         for (int j = 0; j + 1 < n; j++) {
//           if (1 == matrix[i][j]) {
//             dp[i][j][k] = dp[i + 1][j][k - 1] && dp[i][j + 1][k - 1] &&
//                           dp[i + 1][j + 1][k - 1];
//             if (dp[i][j][k] == true) {
//               result++;
//             }
//           }
//         }
//       }
//     }
//     return result;
//   }
// };
// 用了一层k来表示数量，也可以不用，滚动更新
class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int k_max = min(m, n) + 1;
    int result = 0;
    for (int k = 1; k <= k_max; k++) {
      for (int i = 0; i + 1 + k - 1 - 1 < m; i++) {
        for (int j = 0; j + 1 + k - 1 - 1 < n; j++) {
          if (matrix[i][j] && 1 == k) {
            result++;
          } else if (matrix[i][j]) {
            // dp[i][j][k] = dp[i + 1][j][k - 1] && dp[i][j + 1][k - 1] &&
            //               dp[i + 1][j + 1][k - 1];
            matrix[i][j] =
                matrix[i + 1][j] && matrix[i][j + 1] && matrix[i + 1][j + 1];
            result += matrix[i][j];
          }
        }
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
  //   vector<vector<int>> matrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
  int result = solution.countSquares(matrix);
  std::cout << "result: " << result << std::endl;
}