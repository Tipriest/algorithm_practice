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
  int maximumNumberOfStringPairs(vector<string> &words) {
    int result = 0;
    unordered_set<string> uset;
    for(string word: words){
      string word_v(word.rbegin(), word.rend());
      if (uset.find(word_v) == uset.end()) {
        uset.insert(word);
      }else{
        result++;
        uset.erase(word_v);
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<string> words = {"tg", "gf", "oz", "nd", "ks",
                          "fo", "ac", "gl", "gt", "fg"};
  int result = solution.maximumNumberOfStringPairs(words);
  std::cout << "result: " << result << std::endl;
}