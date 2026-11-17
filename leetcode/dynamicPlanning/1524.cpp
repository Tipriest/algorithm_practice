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

class Solution {
  const int mod = 1e9 + 7;

public:
  int numOfSubarrays(vector<int> &arr) {
    int n = arr.size();
    // 包含这个值的偶数组，或者奇数组的数量
    vector<int> Even(n, 0), Odd(n, 0);
    if (0 == arr[0] % 2) {
      Even[0]++;
    } else {
      Odd[0]++;
    }
    for (int i = 1; i < n; i++) {
      if (0 == arr[i] % 2) {
        // 当前的这个数是偶数
        Even[i] = Even[i - 1] + 1;
        Odd[i] = Odd[i - 1];
      } else {
        // 当前的这个数是奇数
        Even[i] = Odd[i - 1];
        Odd[i] = Even[i - 1] + 1;
      }
    }
    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum = (sum + Odd[i]) % mod;
    }
    return sum;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 3, 5};
  int result = solution.numOfSubarrays(nums);
  std::cout << "result: " << result << std::endl;
}