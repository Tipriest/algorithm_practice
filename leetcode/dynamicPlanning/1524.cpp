#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
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
// 阶乘
int Frac(int i) {
  if (i <= 0) {
    return 1;
  } else if (1 == i) {
    return 1;
  }
  return i * Frac(i - 1);
}
// C n m
int Csel(int n, int m) { return Frac(n) / (Frac(m) * Frac(n - m)); }
class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
      prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    int result = 0;
    vector<int> odd_num(n, 0), even_num(n, 0);
    for (int i = 0; i < n; i++) {
      odd_num[i] += (0 != prefixSum[i] % 2);
      even_num[i] += (0 == prefixSum[i] % 2);
    }
    if (0 == prefixSum[n - 1] % 2) {
      
    } 
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 3, 5};
  int result = solution.numOfSubarrays(nums);
  std::cout << "result: " << result << std::endl;
}