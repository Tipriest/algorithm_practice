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
  bool hasCommonLanguage(unordered_set<int> &personA, vector<int> &personB) {
    for (int language : personB) {
      if (personA.find(language) != personA.end()) {
        return true;
      }
    }
    return false;
  }
  int minimumTeachings(int n, vector<vector<int>> &mp_languages,
                       vector<vector<int>> &friendships) {
    vector<unordered_set<int>> mp_languages_uset;
    for (vector<int> &sp_languages : mp_languages) {
      unordered_set<int> sp_languages_uset;
      for (int language : sp_languages) {
        sp_languages_uset.insert(language);
      }
      mp_languages_uset.push_back(sp_languages_uset);
    }
    unordered_set<int> cannotCommPeoples = {};
    for (vector<int> &friendship : friendships) {
      int personA = friendship[0] - 1, personB = friendship[1] - 1;
      if (hasCommonLanguage(mp_languages_uset[personA],
                            mp_languages[personB])) {
        continue;
      } else {
        cannotCommPeoples.insert(personA);
        cannotCommPeoples.insert(personB);
      }
    }
    vector<int> hasKnownLanguages(n, 0);
    for (int cannotCommPeople : cannotCommPeoples) {
      for (int language : mp_languages[cannotCommPeople]) {
        hasKnownLanguages[language - 1]++;
      }
    }
    return cannotCommPeoples.size() -
           *max_element(hasKnownLanguages.begin(), hasKnownLanguages.end());
  }
};
int main() {
  // 示例二叉树
  Solution solution;
  vector<vector<int>> languages = {{3, 11, 5, 10, 1, 4, 9, 7, 2, 8, 6},
                                   {5, 10, 6, 4, 8, 7},
                                   {6, 11, 7, 9},
                                   {11, 10, 4},
                                   {6, 2, 8, 4, 3},
                                   {9, 2, 8, 4, 6, 1, 5, 7, 3, 10},
                                   {7, 5, 11, 1, 3, 4},
                                   {3, 4, 11, 10, 6, 2, 1, 7, 5, 8, 9},
                                   {8, 6, 10, 2, 3, 1, 11, 5},
                                   {5, 11, 6, 4, 2}};
  vector<vector<int>> friendships = {{7, 9}, {3, 7}, {3, 4}, {2, 9},
                                     {1, 8}, {5, 9}, {8, 9}};
  int result = solution.minimumTeachings(3, languages, friendships);
  std::cout << "result: " << result << std::endl;
  return 0;
}