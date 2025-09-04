#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
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
class Solution {
public:
  int minimumDeletions(string word, int k) {
    unordered_map<char, int> umap1;
    for (char ch : word) {
      umap1[ch]++;
    }
    map<int, int> map2;
    for (auto pair : umap1) {
      map2[pair.second] += pair.second;
    }
    vector<pair<int, int>> vp(map2.begin(), map2.end());
    sort(vp.begin(), vp.end(), [](auto pair1, auto pair2){return pair1.first < pair2.first;});
    int n = vp.size();
    vector<int> prefix_sum(n+1, 0);
    for(int i = 1; i <= n; i++){
        prefix_sum[i] = prefix_sum[i-1]+vp[i-1].second;
    }
    int maximum_exist_len = 0;
    for(int left_idx = 0; left_idx<n; left_idx++){
        for(int right_idx = left_idx; right_idx<n && vp[right_idx].first-vp[left_idx].first<=k; right_idx ++){
          maximum_exist_len = max(maximum_exist_len,
                                  prefix_sum[right_idx] - prefix_sum[left_idx]);
        }
    }
    return word.size() - maximum_exist_len;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  string word = "aabcaba";
  int result = solution.minimumDeletions(word, 0);
  std::cout << "result: " << result << std::endl;
}