#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <numeric>
#include <limits.h>
#include <map>
#include <math.h>
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
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    int total_apple = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.begin(), capacity.end(), std::greater());
    int n = capacity.size();
    int res = 0;
    for(int cap : capacity){
        total_apple -= cap;
        res++;
        if(total_apple <= 0){
            return res;
        }
    }
    return res;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> apple = {1, 3, 2};
  vector<int> capacity = {4, 3, 1, 5, 2};
  int result = solution.minimumBoxes(apple, capacity);
  std::cout << "result: " << result << std::endl;
}