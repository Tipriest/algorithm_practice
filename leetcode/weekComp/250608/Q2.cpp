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
const int MOD = 1000000007;
int fra(int n) {
  if (n <= 1) return 1;
  return (int)((1LL * n * fra(n - 1)) % MOD);
}
class Solution {
public:
  int countPermutations(vector<int> &complexity) {
    int n = complexity.size();
    int min_comp = *min_element(complexity.begin(), complexity.end());
    if (complexity[0] != min_comp) {
      return 0;
    }
    int meet_num = 0;
    for(int i = 0; i < n; i++){
        if(complexity[i] == min_comp){
            meet_num++;
            if(meet_num>1){
                return 0;
            }
        }
    }
    int result = fra(n-1);
    return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> complexity = {1, 2, 3};
  int result = solution.countPermutations(complexity);
  std::cout << "result: " << result << std::endl;
}