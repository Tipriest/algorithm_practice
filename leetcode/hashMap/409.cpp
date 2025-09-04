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
  int longestPalindrome(string s) {
    unordered_map<char, int> umap;
    for (char ch : s) {
      umap[ch]++;
    }
    bool hasOdd = false;
    int result = 0;
    for (auto iter : umap) {
      if (1 == iter.second % 2) {
        result += iter.second - 1;
        hasOdd = true;
      } else {
        result += iter.second;
      }
    }
    return result + hasOdd;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.longestPalindrome("abccccdd");
  std::cout << "result: " << result << std::endl;
}