#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <unordered_set>
#include <vector>
#include <map>
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
  int findLHS(vector<int> &nums) {
    map<int, int> map;
    for (int num : nums) {
      map[num]++;
    }
    vector<pair<int, int>> pairs(map.begin(), map.end());
    int n = pairs.size();
    int biggest = 0;
    for(int i = 1; i < n; i++){
        if(pairs[i].first - pairs[i-1].first == 1){
            biggest = max(biggest, pairs[i].second+pairs[i-1].second);
        }
    }
    return biggest;
  }
};

int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  int result = solution.findLHS(nums);
  std::cout << "result: " << result << std::endl;
}