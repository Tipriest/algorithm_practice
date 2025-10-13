#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
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
  inline bool isAnagrams(string &word1, string &word2) {
    if (word1.size() != word2.size()) {
      return false;
    }
    if (word1 == word2) {
      return true;
    }
    vector<int> ch_count(26, 0);
    for (char ch : word1) {
      ch_count[ch - 'a']++;
    }
    for (char ch : word2) {
      ch_count[ch - 'a']--;
      if (ch_count[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
  vector<string> removeAnagrams(vector<string> &words) {
    vector<string> result;
    for (string word : words) {
      if (result.empty()) {
        result.push_back(word);
      }
      if (!isAnagrams(result[result.size() - 1], word)) {
        result.push_back(word);
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<string> nums = {"abba", "baba", "bbaa", "cd", "cd"};
  vector<string> result = solution.removeAnagrams(nums);
  //    std::cout << "result: " << result << std::endl;
}