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
  static string lowerWord(const string &word) {
    string res = word;
    for (char &ch : res) {
      ch = tolower(ch);
    }
    return res;
  }
  static string delVoxelWord(const string &word) {
    string res = word;
    for (char &ch : res) {
      ch = tolower(ch);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        ch = '*';
      }
    }
    return res;
  }
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    unordered_set<string> words_perfect_set(wordlist.begin(), wordlist.end());
    unordered_map<string, string> words_lower_map;
    unordered_map<string, string> words_no_vow_map;
    for (const string &w : wordlist) {
      string lw = lowerWord(w);
      if (!words_lower_map.count(lw)) {
        words_lower_map[lw] = w;
      }
      string nvw = delVoxelWord(w);
      if (!words_no_vow_map.count(nvw)) {
        words_no_vow_map[nvw] = w;
      }
    }
    vector<string> result;
    for (const string &q : queries) {
      if (words_perfect_set.count(q)) {
        result.push_back(q);
        continue;
      }
      string lw = lowerWord(q);
      auto it1 = words_lower_map.find(lw);
      if (it1 != words_lower_map.end()) {
        result.push_back(it1->second);
        continue;
      }
      string nvw = delVoxelWord(q);
      auto it2 = words_no_vow_map.find(nvw);
      if (it2 != words_no_vow_map.end()) {
        result.push_back(it2->second);
      } else {
        result.push_back("");
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
  vector<string> queries = {"kite", "Kite", "KiTe", "Hare", "HARE",
                            "Hear", "hear", "keti", "keet", "keto"};
  vector<string> result = solution.spellchecker(wordlist, queries);
  //   std::cout << "result: " << result << std::endl;
  return 0;
}