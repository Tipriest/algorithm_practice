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
  int maxDifference(string s) {
    unordered_map<char, int> umap;
    for(char ch: s){
        umap[ch]++;
    }
    int max_odd = 0, min_even = INT32_MAX;
    for(auto sum : umap){
      if (sum.second % 2 == 0 && sum.second < min_even) {
        min_even = sum.second;
      } else if (sum.second % 2 == 1 && sum.second > max_odd) {
        max_odd = sum.second;
      }
    }
    return max_odd - min_even;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  string s = "aaaaabbc";
  int result = solution.maxDifference(s);
  std::cout << "result: " << result << std::endl;
}