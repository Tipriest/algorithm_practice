#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
#include <numeric>
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
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    // 创建下标数组
    vector<pair<int, int>> vp;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        vp.push_back({nums[i], i});
    }
    sort(vp.begin(), vp.end(), [](auto pair1, auto pair2) {return pair1.first > pair2.first;});
    vector<pair<int, int>> vp2(vp.begin(), vp.begin()+k);
    sort(vp2.begin(), vp2.end(),
         [](auto pair1, auto pair2) { return pair1.second < pair2.second; });
    vector<int> result;
    for(int i = 0; i <k; i++){
        result.push_back(vp2[i].first);
    }
    return result;
  }
};
int main() {
   // 示例二叉树
   Solution solution;
   vector<int> nums = {-1, -2, 3, 4};
   vector<int> result = solution.maxSubsequence(nums, 3);
//    std::cout << "result: " << result << std::endl;
}