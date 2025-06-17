#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int result = 0;
    for (int i = n; i >= 1; i--) {
      for (int j = i; j <= n; j++) {
        if (s[i - 1] != s[j - 1]) {
          dp[i][j] = dp[i][j - 1];
          continue;
        }
        if (i == j) {
          dp[i][j] = 1;
        } else if (1 == abs(i - j)) {
          dp[i][j] = 2;
        } else {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
        result = max(result, dp[i][j]);
      }
    }
    return result;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string word1 =
      "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfcke"
      "xmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiy"
      "pvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsg"
      "zdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmd"
      "uxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuz"
      "nolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlb"
      "eguackbdkftzbnynmcejtwudocemcfnuzbttcoew";
  int result = solution.longestPalindromeSubseq(word1);
  std::cout << "result: " << result << std::endl;
}