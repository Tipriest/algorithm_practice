#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
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
  struct MyPair {
    MyPair(int _v, int _n) {
      value = _v;
      num = _n;
    }
    int value;
    int num;
    bool operator<(const MyPair &other) const {
      if (num != other.num) {
        return num < other.num;
      } else {
        return value < other.value;
      }
      std::cout << "err" << std::endl;
      return false;
    }
    bool operator>(const MyPair &other) const {
      if (num != other.num) {
        return num > other.num;
      } else {
        return value > other.value;
      }
      std::cout << "err" << std::endl;
      return false;
    }
  };
  int calFrontXValue(const unordered_map<int, int> &umap, int x) { 
    std::priority_queue<MyPair> pque;
    for(auto iter : umap){
        pque.push(MyPair(iter.first, iter.second));
    }
    int num_cc = x;
    int result = 0;
    while(num_cc && !pque.empty()){
        result += pque.top().num*pque.top().value;
        num_cc--;
        pque.pop();
    }
    return result;
   }
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    unordered_map<int, int> umap;
    vector<int> result;
    int n = nums.size();
    for (int i = 0; i + k - 1 < n; i++) {
      //  更新umap
      if (0 == i) {
        for (int j = i; j < i + k; j++) {
          umap[nums[j]]++;
        }
      } else {
        umap[nums[i - 1]]--;
        umap[nums[i + k - 1]]++;
      }
      result.push_back(calFrontXValue(umap, x));
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
  vector<int> result = solution.findXSum(nums, 6, 2);
  std::cout << "result: " << 1 << std::endl;
}