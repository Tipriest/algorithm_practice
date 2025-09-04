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
  vector<int> recoverOrder(vector<int> &orders, vector<int> &friends) {
    unordered_set<int> friends_set;
    for (int i = 0; i < friends.size(); i++) {
      friends_set.insert(friends[i]);
    }
    vector<int> result;
    for(int order : orders){
      if (friends_set.find(order)!= friends_set.end()){
        result.push_back(order);
      }
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {3, 1, 2, 5, 4};
  vector<int> friends = {1, 3, 4};
  vector<int> result = solution.recoverOrder(nums, friends);
  // std::cout << "result: " << result << std::endl;
}