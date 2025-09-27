#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
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
struct Pack {
  Pack(int a, vector<char> &b) {
    num = a;
    chs = b;
  }
  // 出现的频数
  int num;
  // 这个频数的字母
  vector<char> chs;
  bool operator>(const Pack &other) const {
    if (chs.size() != other.chs.size()) {
      return chs.size() > other.chs.size();
    }
    return num > other.num;
  }
  bool operator<(const Pack &other) const { return !operator>(other); }
};
class Solution {
public:
  string majorityFrequencyGroup(string s) {
    unordered_map<char, int> umap;
    for (char ch : s) {
      umap[ch]++;
    }
    unordered_map<int, vector<char>> umap2;
    for (auto it : umap) {
      umap2[it.second].push_back(it.first);
    }
    for (auto it : umap2) {
      pque.push(Pack(it.first, it.second));
    }
    Pack ptop = pque.top();
    set<char> ress;
    for (char ch : ptop.chs) {
      ress.insert(ch);
    }
    string res;
    for (auto it : ress) {
      res.push_back(it);
    }
    return res;
  }
  priority_queue<Pack> pque;
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {-84, 28, 12};
  string result = solution.majorityFrequencyGroup("aaabbbccdddde");
  std::cout << "result: " << result << std::endl;
  return 0;
}