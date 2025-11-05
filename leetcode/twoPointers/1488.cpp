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
  vector<int> avoidFlood(vector<int> &rains) {
    // 没有第0号湖泊
    int n = *max_element(rains.begin(), rains.end());
    // 第0个湖泊是不存在的，剩下第1到第n个湖泊
    vector<pair<bool, int>> lakes(n+1, make_pair(false, -1));
    // 慢指针是用来指示现在的晴天的，快指针是用来指示现在需要排水的湖泊的
    int l = 0, r = 0;
    while(true){
        // 先去找到现在的快慢指针
      while (l < rains.size() && 0 != rains[l]) {
        l++;
      }
      //
      while (r < rains.size()) {
        // 如果是晴天，过
        if(0 == rains[r]){
            r++;
        } else if (0 != rains[r]){
            if(false == lakes[r].first){
              lakes[r].first = true;
              lakes[r].second = r;
            }else{
                break;
            }
        }
      }
      if (rains.size() == l && rains.size() > r){
        return {};
      }else if(l > lakes[r].second){
        return {};
      }
    }
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> rains = {7, 1, 5, 3, 6, 4};
  vector<int> result = solution.avoidFlood(rains);
  //   std::cout << "result: " << result << std::endl;
  return 0;
}