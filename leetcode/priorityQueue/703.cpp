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
class KthLargest {
public:
  KthLargest(int _k, vector<int> &nums) {
    k = _k;
    for (int num : nums) {
      if (pq.size() < k) {
        pq.push(num);
      } else if (pq.top() < num) {
        pq.pop();
        pq.push(num);
      } else {
        continue;
      }
    }
  }
  int add(int val) {
    if (pq.size() < k) {
      pq.push(val);
    } else if (pq.top() < val) {
      pq.pop();
      pq.push(val);
    }
    return pq.top();
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  int k;
};
int main() {
  // 示例二叉树
  vector<int> nums = {4, 5, 8, 2};
  KthLargest m(3, nums);
  int result = m.add(3);
  result = m.add(5);
  result = m.add(10);
  result = m.add(9);
  result = m.add(4);
  std::cout << "result: " << result << std::endl;
  return 0;
}