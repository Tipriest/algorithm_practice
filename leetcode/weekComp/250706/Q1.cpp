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

class Solution {
public:
  vector<string> validateCoupons(vector<string> &codes,
                                 vector<string> &businessLine,
                                 vector<bool> &isActive) {
    unordered_set<char> code_ch_set;
    unordered_set<string> buiness_line_set;
    code_ch_set.insert('_');
    for (int i = 0; i < 10; i++) {
      code_ch_set.insert('0' + i);
    }
    for (int i = 0; i < 26; i++) {
      code_ch_set.insert('a' + i);
      code_ch_set.insert('A' + i);
    }
    buiness_line_set.insert("electronics");
    buiness_line_set.insert("grocery");
    buiness_line_set.insert("pharmacy");
    buiness_line_set.insert("restaurant");
    int n = codes.size();
    vector<pair<string, string>> pairs;
    for (int i = 0; i < n; i++) {
      if (isActive[i] == false) {
        continue;
      }
      if(codes[i].size() == 0){
        continue;
      }
      if (buiness_line_set.find(businessLine[i]) == buiness_line_set.end()) {
        continue;
      }
      bool code_ch_satisfy = true;
      for (char ch : codes[i]) {
        if (code_ch_set.find(ch) == code_ch_set.end()) {
          code_ch_satisfy = false;
          continue;
        }
      }
      if (code_ch_satisfy == false) {
        continue;
      }
      pairs.push_back({codes[i], businessLine[i]});
    }
    sort(pairs.begin(), pairs.end(), [](auto pair1, auto pair2) {
      if (pair1.second[0] < pair2.second[0]) {
        return true;
      } else if (pair1.second[0] > pair2.second[0]) {
        return false;
      }
      int n = min(pair1.first.size(), pair2.first.size());
      for (int i = 0; i < n; i++) {
        if (pair1.first[i] < pair2.first[i]) {
          return true;
        } else if (pair1.first[i] > pair2.first[i]) {
          return false;
        }
      }
      return pair1.first.size()< pair2.first.size();
    });
    n = pairs.size();
    vector<string> result;
    for(int i = 0; i <n; i++){
        result.push_back(pairs[i].first);
    };
     return result;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<string> codes = {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"};
  vector<string> businessLine = {"grocery", "electronics", "invalid"};
  vector<bool> isActive = {false, true, true};
  vector<string> result =
      solution.validateCoupons(codes, businessLine, isActive);
  //   std::cout << "result: " << result << std::endl;
  cout<<1<<endl;
}