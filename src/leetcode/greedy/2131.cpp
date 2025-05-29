#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> umap;
    int result = 0;
    vector<int> same_record(26, 0);
    for (string word : words) {
      if (word[0] == word[1]) {
        same_record[word[0] - 'a'] += 1;
        continue;
      }
      if (umap.find(string(word.rbegin(), word.rend())) == umap.end() ||
          umap[string(word.rbegin(), word.rend())] == 0) {
        umap[word]++;
      } else {
        umap[string(word.rbegin(), word.rend())]--;
        result += 4;
        continue;
      }
    }
    int max_value = 0;
    int exist_odd = 0;
    for (int i : same_record) {
      if (i % 2 == 0) {
        result += i * 2;
      } else {
        result += (i-1) * 2;
        exist_odd = 1;
      }
    }
    return result + exist_odd * 2;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<string> words = {"fo", "fo", "fq", "qo", "qf", "ff", "qq", "qf",
                          "of", "of", "qf", "oo", "of", "of", "qf", "of"};
  int result = solution.longestPalindrome(words);
  std::cout << "result: " << result << std::endl;
}