#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <math.h>
#include <limits.h>
#include <queue>
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
  long convertFromStrToNum(string s) {
    long result = 0;
    for(char c : s){
        result = result * 10 + c - '0';
    }
    return result;
  }
  bool isPrimeNumber(long num) {
    if(num <= 1){
        return false;
    }
    long sqrt_num = sqrt(num);
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
  }
  long long sumOfLargestPrimes(string s) {
    int n = s.size();
    unordered_set<long> uset;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n - i+1; j++) {
        string temp = s.substr(i, j);
        uset.insert(convertFromStrToNum(temp));
      }
    }
    priority_queue<long> p_qu;
    for(long num : uset){
        if(isPrimeNumber(num)){
          p_qu.push(num);
        }
    }
    long long result = 0;
    int i = 0;
    while(p_qu.size()>0 && i < 3){
        result+=p_qu.top();
        p_qu.pop();
        i++;
    }

    return result;
  }
};
int main() {
    // 示例二叉树
    Solution solution;
    string s = "41";
    int result = solution.sumOfLargestPrimes(s);
    std::cout << "result: " << result << std::endl;
}