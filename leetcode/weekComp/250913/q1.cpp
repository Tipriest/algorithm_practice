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
  int smallestAbsent(vector<int> &nums) {
    unordered_set<int> uset;
    int sum = 0;
    for(int num : nums){
        sum+= num;
        uset.insert(num);
    }
    // 一会检查一下这里是为什么
    int avg = sum / nums.size();
    avg = max(0, avg);
    for(int i = avg+1; i < 102; i++){
        if(uset.find(i)== uset.end()){
            return i;
        }
    }
    return 0;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {-84, 28, 12};
  int result = solution.smallestAbsent(nums);
  std::cout << "result: " << result << std::endl;
  return 0;
}