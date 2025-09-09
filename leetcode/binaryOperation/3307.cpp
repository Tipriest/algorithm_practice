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
  int nearest_2_times_num(long long k) {
    int i = 0;
    while (k > pow(2, i)) {
      i++;
    }
    return i - 1;
  }
  char kthCharacter(long long k, vector<int> &operations) {
    int total_change_num = 0;
    while (1 != k) {
      int times = nearest_2_times_num(k);
      k -= pow(2, times);
      total_change_num += operations[times];
    }
    return 'a' + total_change_num;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  int k = 10;
  vector<int> operations = {0, 1, 0, 1};
  char result = solution.kthCharacter(k, operations);
  std::cout << "result: " << result << std::endl;
}