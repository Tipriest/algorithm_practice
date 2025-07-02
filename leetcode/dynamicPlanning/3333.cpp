#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  const int mod = 1e9 + 7;

public:
  int possibleStringCount(string word, int k) {
    // cout << mod << endl;
    int n = word.size();
    if (n < k) {
      return 0;
    } else if (n == k) {
      return 1;
    }
    stack<char> st;
    vector<int> segs;
    int temp_segs_num = 0;
    st.push(word[0]);
    for (int i = 1; i < n; i++) {
      if (word[i] == st.top()) {
        temp_segs_num++;
      } else {
        st.push(word[i]);
        // if (temp_segs_num != 0) {
        //   segs.push_back(temp_segs_num);
        //   temp_segs_num = 0;
        // }
        segs.push_back(temp_segs_num);
        temp_segs_num = 0;
      }
    }
    segs.push_back(temp_segs_num);
    int m = segs.size();
    long total_result = 1;
    for (int num : segs) {
      total_result = total_result * (num + 1) % mod;
    }
    if (k <= m) {
      return total_result;
    }
    vector<vector<long>> dp(m + 1, vector<long>(k - m - 1 + 1, 0));
    for (int i = 0; i < m + 1; i++) {
      dp[i][0] = 1;
    }
    for (int j = 0; j < k - m; j++) {
      dp[0][j] = 1;
    }
    vector<int> s(k - m + 1, 0);
    for (int i = 1; i < m + 1; i++) {
      s[0] = 0;
      for (int l = 1; l < k - m + 1; l++) {
        s[l] = s[l - 1] + dp[i - 1][l - 1] % mod;
      }
      for (int j = 1; j < k - m; j++) {
        dp[i][j] = s[j + 1] - s[max(0, j - segs[i-1])];
        dp[i][j] = dp[i][j] % mod;
      }
    }
    int result = total_result - dp[m][k - m - 1];
    while (result < 0) {
      result += mod;
    }
    while (result > mod) {
      result -= mod;
    }

    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string word = "iiiiiiiiitttttttllllllbbbbbbbkkkkvvvccccvvvvvvvvvaaaaaaapaaall"
                "lllllllljjjja";
  int k = 48;
  int result = solution.possibleStringCount(word, k);
  std::cout << "result: " << result << std::endl;
}