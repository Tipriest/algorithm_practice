#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <set>
#include <unordered_set>
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
struct Pos {
  int x = 0, y = 0;
  void operator+=(char ch) {
    if ('U' == ch) {
      y += 1;
    } else if ('D' == ch) {
      y -= 1;
    } else if ('L' == ch) {
      x -= 1;
    } else if ('R' == ch) {
      x += 1;
    }
  }
  void operator-=(char ch) {
    if ('U' == ch) {
      y -= 1;
    } else if ('D' == ch) {
      y += 1;
    } else if ('L' == ch) {
      x += 1;
    } else if ('R' == ch) {
      x -= 1;
    }
  }
  // bool operator==(const Pos &other) const {
  //   return (x == other.x) && (y == other.y);
  // }
  // bool operator<(const Pos &other) const {
  //   if(x != other.x){
  //     return x < other.x;
  //   }
  //     return y < other.y;
  // }
  // bool operator>(const Pos &other) const {
  //   return operator<(other);
  // }
};
class Solution {
public:
  int distinctPoints(string s, int k) {
    int n = s.size();
    Pos p;
    for (int i = 0; i < k; i++) {
      p += s[i];
    }
    ms.insert({p.x, p.y});
    for(int i = 1; i + k-1 < n; i++){
      p -= s[i-1];
      p += s[i+k-1];
      ms.insert({p.x, p.y});
    }
    return ms.size();
  }
  set<pair<int, int>> ms;
};
int main() {
  // 示例二叉树
  Solution solution;
  string s = "LUL";
  int result = solution.distinctPoints(s, 1);
  std::cout << "result: " << result << std::endl;
  return 0;
}