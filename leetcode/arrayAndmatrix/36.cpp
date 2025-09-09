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
  bool isValidSudoku(vector<vector<char>> &boards) {
    unordered_set<char> uset;
    for (vector<char> board : boards) {
      for (char ch : board) {
        if ('.' == ch) {
          continue;
        } else {
          if (uset.find(ch) != uset.end()) {
            return false;
          } else {
            uset.insert(ch);
          }
        }
      }
      uset.clear();
    }
    int n = boards[0].size();
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if ('.' == boards[i][j]) {
          continue;
        } else {
          if (uset.find(boards[i][j]) != uset.end()) {
            return false;
          } else {
            uset.insert(boards[i][j]);
          }
        }
      }
      uset.clear();
    }
    n = boards[0].size() / 3;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int m = 0; m < 3; m++) {
          for (int n = 0; n < 3; n++) {
            if ('.' == boards[i * 3 + m][j * 3 + n]) {
              continue;
            } else {
              if (uset.find(boards[i * 3 + m][j * 3 + n]) != uset.end()) {
                return false;
              } else {
                uset.insert(boards[i * 3 + m][j * 3 + n]);
              }
            }
          }
        }
        uset.clear();
      }
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  int result = solution.isValidSudoku(board);
  std::cout << "result: " << result << std::endl;
}
