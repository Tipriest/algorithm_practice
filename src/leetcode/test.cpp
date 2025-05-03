/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> father;
  int numberOfComponents(vector<vector<int>> &properties, int k) {
    int n = properties.size();
    father.clear();
    for (int i = 0; i < n; i++) {
      father.push_back(i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        // 如果已经是连通分支了, 直接跳过
        if (findFather(i) == findFather(j)) {
          continue;
        }
        // 如果不是连通分支但是有交集
        if (intersect(properties[i], properties[j]) >= k) {
          father[j] = findFather(i);
        }
      }
    }
    unordered_set<int> uset;
    for (int i = 0; i < n; i++) {
      uset.insert(findFather(i));
    }
    return uset.size();
  }
  int intersect(vector<int> &property1, vector<int> &property2) {
    sort(property1.begin(), property1.end());
    sort(property2.begin(), property2.end());
    int index1 = 0;
    int index2 = 0;
    int m = property1.size();
    int same_num = 0;
    while (index1 < m && index2 < m) {
      if (property1[index1] == property2[index2]) {
        same_num++;
        index1++;
        index2++;
      } else if (property1[index1] > property2[index2]) {
        index2++;
      } else if (property1[index1] < property2[index2]) {
        index1++;
      }
    }
    return same_num;
  }
  int findFather(int i) {
    while (father[i] != i) {
      i = father[i];
    }
    return i;
  }
};

int main() {
  // 示例二叉树
  vector<int> nums{1, 2, 3};
  swap(nums[0], nums[1]);
  std::cout<<nums[0]<<nums[1]<<nums[2]<<std::endl;
}