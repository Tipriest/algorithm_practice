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

class FindSumPairs {
public:
  vector<int> nums1, nums2;
  unordered_map<int, int> umap1, umap2;
  FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    for (int num : nums1) {
      umap1[num]++;
    }
    for (int num : nums2) {
      umap2[num]++;
    }
  }

  void add(int index, int val) {
    if (umap2.find(nums2[index]) != umap2.end()) {
      umap2[nums2[index]]--;
      nums2[index] += val;
      umap2[nums2[index]]++;
    }
  }

  int count(int tot) {
    int result = 0;
    for (auto pair : umap1) {
      result += umap2[tot - pair.first]*pair.second;
    }
    return result;
  }
};
int main() {
  // 示例二叉树
  vector<int> nums1 = {1, 1, 2, 2, 2, 3};
  vector<int> nums2 = {1, 4, 5, 2, 5, 4};
  int index = 3;
  int val = 2;
  int tot = 7;
  FindSumPairs *obj = new FindSumPairs(nums1, nums2);
  int param_1 = obj->count(7);
  obj->add(3, 2);
  param_1 = obj->count(8);
  param_1 = obj->count(4);
  obj->add(0, 1);
  obj->add(1, 1);
  param_1 = obj->count(7);
}