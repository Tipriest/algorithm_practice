#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
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
  int maxSumDistinctTriplet(vector<int> &x, vector<int> &y) {
    vector<pair<int, int>> vp_y;
    int n = y.size();
    for (int i = 0; i < n; i++){
        vp_y.push_back({i, y[i]});
    }
    sort(vp_y.begin(), vp_y.end(), [](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
    unordered_set<int> uset;
    int result = 0;
    for(int i = 0; i < vp_y.size(); i++){
        if(uset.find(x[vp_y[i].first]) == uset.end()){
            result += vp_y[i].second;
            uset.insert(x[vp_y[i].first]);
            if(uset.size() == 3){
                return result;
            }
        }else{

        }
    }
    return -1;
  }
};

int main() {
   // 示例二叉树
   Solution solution;
   vector<int> x = {1, 2, 1, 3, 2}, y = {5, 3, 4, 6, 2};
   int result = solution.maxSumDistinctTriplet(x, y);
   std::cout << "result: " << result << std::endl;
}