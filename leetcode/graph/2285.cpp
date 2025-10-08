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
  long long maximumImportance(int n, vector<vector<int>> &roads) {
   vector<int> degree(n, 0);
   for(vector<int> road: roads){
      degree[road[0]]++;
      degree[road[1]]++;
   }
   sort(degree.begin(), degree.end(), std::greater());
   long long res = 0;
   for(int i = 0; i < degree.size(); i++){
      res += (long long)(n - i)*degree[i];
   }
   return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
  long long result = solution.maximumImportance(5, roads);
  std::cout << "result: " << result << std::endl;
  return 0;
}