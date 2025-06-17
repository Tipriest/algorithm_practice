#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
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

class Solution {
public:
  int getMaxLen(vector<int> &nums) {
    int n = nums.size();
    vector<int> positive(n, 0);
    vector<int> negative(n, 0);
    if (nums[0] > 0) {
      positive[0] = 1;
    } else if (nums[0] < 0) {
      negative[0] = 1;
    }
    for (int i = 1; i < n; i++) {
      if (0 == nums[i]) {
        positive[i] = 0;
        negative[i] = 0;
      } else if (nums[i] > 0) {
        positive[i] = positive[i - 1] + 1;
        if (negative[i - 1] > 0) {
          negative[i] = negative[i - 1] + 1;
        } else {
          negative[i] = 0;
        }
      } else if (nums[i] < 0) {
        negative[i] = positive[i - 1] + 1;
        if(negative[i-1]>0){
          positive[i] = negative[i - 1]+1;
        }else{
            positive[i] = 0;
        }
      }
    }
    return *max_element(positive.begin(), positive.end());
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {5, -20, -20, -39, -5, 0,  0,   0,   36, -32,
                      0, -7,  -10, -7,  21, 20, -12, -34, 26, 2};
  int result = solution.getMaxLen(nums);
  std::cout << "result: " << result << std::endl;
}