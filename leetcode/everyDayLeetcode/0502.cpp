

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    int i = 0;
    char left = 'L';
    while (i < n) {
      int j = i;
      while (j < n && dominoes[j] != '.') {
        j++;
      }
      char right = j == n ? 'R' : dominoes[j];
      if (left == right) {
        while (i < j) {
          dominoes[i++] = left;
        }
      } else if (left == 'R' && right == 'L') {
        int k = j - 1;
        while (i < k) {
          dominoes[i++] = 'R';
          dominoes[k--] = 'L';
        }
      }
      left = right;
      i = j + 1;
    }
    return dominoes;
  }
};

int main() {
  // 示例二叉树
  string dominoes = ".L.R...LR..L..";
  Solution solution;
  string result = solution.pushDominoes(dominoes);
  std::cout << "result: " << result << std::endl;
}