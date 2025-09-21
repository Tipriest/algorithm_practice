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
class MovingAverage {
public:
  /** Initialize your data structure here. */
  MovingAverage(int _size) {
    sum = 0;
    size = _size;
  }
  double next(int val) {
    if (que.size() >= size) {
      sum -= que.front();
      que.pop();
    }
    que.push(val);
    sum += val;
    return (double)sum / que.size();
  }
  int sum;
  int size;
  queue<int> que;
};
int main() {
  // 示例二叉树
  int size = 3, val = 1;
  MovingAverage *obj = new MovingAverage(3);
  double param_1 = obj->next(1);
  param_1 = obj->next(10);
  param_1 = obj->next(3);
  param_1 = obj->next(5);
  return 0;
}