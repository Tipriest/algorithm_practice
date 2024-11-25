#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
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
  int getLeastFrequentDigit(int n) {
    unordered_map<int, int> umap;
    while (0 != n) {
      int temp = n % 10;
      n = n / 10;
      umap[temp]++;
    }
    int min_num = 50, min_v = 10;
    for(auto iter : umap){
      if (iter.second > min_num){
         continue;
      } else if (iter.second == min_num) {
        min_v = min(iter.first, min_v);
      } else if (iter.second < min_num) {
        min_v = iter.first;
        min_num = iter.second;
      }
    }
    return min_v;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.getLeastFrequentDigit(1553322);
  std::cout << "result: " << result << std::endl;
}