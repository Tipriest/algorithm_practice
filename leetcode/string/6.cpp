#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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
class Solution {
public:
  string convert(string s, int numRows) {
    vector<vector<char>> vec(numRows, vector<char>{});
    vector<int> iter_list;
    for (int i = 0; i < numRows; i++) {
      iter_list.push_back(i);
    }
    for (int i = numRows - 2; i >= 1; i--) {
      iter_list.push_back(i);
    }
    int n = iter_list.size();
    int index = 0;
    for (char ch : s) {
      vec[iter_list[index]].push_back(ch);
      index++;
      index = index % n;
    }
    string result = "";
    for (auto vec_col : vec) {
      for (char vec_row : vec_col) {
        result.push_back(vec_row);
      }
    }

    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "PAYPALISHIRING";
  int numRows = 4; // 可以根据需要修改行数
  string result = solution.convert(s, numRows);
  std::cout << "result: " << result << std::endl;
}