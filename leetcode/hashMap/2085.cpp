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
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> words1_map, words2_map;
    for (string word : words1) {
      words1_map[word]++;
    }
    for (string word : words2) {
      words2_map[word]++;
    }
    int result = 0;
    for (auto iter : words1_map) {
      if (1 == iter.second && 1 == words2_map[iter.first]) {
        result++;
      }else{
        continue;
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<string> words1 = {"leetcode", "is", "amazing", "as", "is"};
  vector<string> words2 = {"amazing", "leetcode", "is"};
  int result = solution.countWords(words1, words2);
  std::cout << "result: " << result << std::endl;
}