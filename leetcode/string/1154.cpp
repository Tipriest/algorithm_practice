#include <algorithm>
#include <functional> //包含std::greater 和 std::less
#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <stack>
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
  int dayOfYear(string date) {
    vector<int> leapyear = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> nonleapyear = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    bool isleapyear = false;
    if (0 == year % 4) {
      if (0 == year % 400) {
        isleapyear = true;
      } else if (0 == year % 100) {
        isleapyear = false;
      } else {
        isleapyear = true;
      }
    }
    int days = 0;
    for(int i = 0; i < month-1; i++){
      if(isleapyear){
         days += leapyear[i];
      }else{
         days += nonleapyear[i];
      }
    }
    days+=day;
    return days;
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int result = solution.dayOfYear("1900-12-31");
  std::cout << "result: " << result << std::endl;
}