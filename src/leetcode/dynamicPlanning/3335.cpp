#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <numeric>
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
  int lengthAfterTransformations(string s, int t) {
    int n = t + 1;
    vector<int> dp(26, 0);
    int mod = 1e9 + 7;
    for (char ch : s) {
      dp[ch - 'a']++;
    }
    for (int i = 1; i < n; i++) {
      int last_z = dp[25];
      for (int j = 25; j >= 0; j--) {
        if (j == 0) {
          dp[j] = last_z;
        } else if (j == 1) {
          dp[j] = (dp[0] + last_z) % mod;
        } else {
          dp[j] = dp[j - 1];
        }
      }
    }
    // cout<<1<<endl;
    return accumulate(dp.begin(), dp.end(), 0);
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "abcyy";
  int result = solution.lengthAfterTransformations(s, 2);
  std::cout << "result: " << result << std::endl;
  std::cout << setiosflags(ios::scientific) << "INT32_MAX: " << (float)INT32_MAX
            << std::endl;
  std::cout << setiosflags(ios::scientific) << "INT32_MIN: " << (float)INT32_MIN
            << std::endl;
  std::cout << setiosflags(ios::scientific) << "INT64_MAX: " << (float)INT64_MAX
            << setiosflags(ios::scientific) << std::endl;
  std::cout << setiosflags(ios::scientific) << "INT64_MIN: " << (float)INT64_MIN
            << std::endl;
  std::cout << setiosflags(ios::scientific) << "LONG_MAX: " << (float)LONG_MAX
            << std::endl;
  std::cout << setiosflags(ios::scientific) << "LONG_MIN: " << (float)LONG_MIN
            << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "LONG_LONG_MAX: " << (float)LONG_LONG_MAX << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "LONG_LONG_MIN: " << (float)LONG_LONG_MIN << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "FLOAT_MAX: " << std::numeric_limits<float>::max() << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "FLOAT_MIN: " << std::numeric_limits<float>::min() << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "DOUBLE_MAX: " << std::numeric_limits<double>::max()
            << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "DOUBLE_MIN: " << std::numeric_limits<double>::min()
            << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "DOUBLE_T_MAX: " << std::numeric_limits<double_t>::max()
            << std::endl;
  std::cout << setiosflags(ios::scientific)
            << "DOUBLE_T_MIN: " << std::numeric_limits<double_t>::min()
            << std::endl;
}