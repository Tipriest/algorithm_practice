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
  int minArrivalsToDiscard(vector<int> &arrivals, int w, int m) {
    int n = arrivals.size();
    vector<bool> used(n, false);
    unordered_map<int, int> umap;
    int discard_num = 0;
    for (int i = 1; i <= w; i++) {
      int day_index = i - 1;
      if (m == umap[arrivals[day_index]]) {
        discard_num++;
        used[day_index] = false;
      } else {
        umap[arrivals[day_index]]++;
        used[day_index] = true;
      }
    }

    for (int i = w + 1; i <= n; i++) {
      int day_index = i - 1;
      int discard_index = i - w - 1;
      if (true == used[discard_index]) {
        umap[arrivals[discard_index]]--;
        used[discard_index] = false;
      }
      if (m == umap[arrivals[day_index]]) {
        discard_num++;
        used[day_index] = false;
      } else {
        umap[arrivals[day_index]]++;
        used[day_index] = true;
      }
    }
    return discard_num;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 3, 9, 9, 7, 3, 5, 9, 7, 2, 6, 10, 9, 7, 9,
                      1, 3, 6, 2, 4, 6, 2, 6, 8, 4, 8, 2,  7, 5, 6};
  int result = solution.minArrivalsToDiscard(nums, 10, 1);
  std::cout << "result: " << result << std::endl;
  return 0;
}