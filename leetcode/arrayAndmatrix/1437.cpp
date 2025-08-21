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
  bool kLengthApart(vector<int> &nums, int k) {
    int consecutive = 0;
    bool ini = false;
    for(int num : nums){
        if(0 == num){
            consecutive++;
        }else{
            if(ini && consecutive < k){
                return false;
            }
            ini = true;
            consecutive = 0;
        }
    }
    return true;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 0, 0, 1, 0, 1};
  int result = solution.kLengthApart(nums, 2);
  std::cout << "result: " << result << std::endl;
}