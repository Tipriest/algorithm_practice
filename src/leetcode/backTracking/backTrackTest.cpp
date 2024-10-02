#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> first;
        unordered_map<int, int> second(n);
        for(int i = 0; i < n; i++){
            second[i] = 0;
        }
        for(int i = 0; i < trust.size(); i++){
            first.insert(trust[i][0]-1);
            second[trust[i][1]-1]+=1;
        }
        for(int i = 0; i < n; i++){
            if((n-1) == second[i] && (first.find(i)==first.end())){
                return i+1;
            }
        }
        return -1;

    }
};
int main(int argc, char** argv){
    Solution solution;
    vector<vector<int>> trust = {{1,3}, {2,3}, {3,1}};
    int result = solution.findJudge(3, trust);
    cout<<"result = "<< result <<endl;
    
    vector<int> A = {1, 2, 3, 4, 5};
    vector<vector<int>> B(5, A);
    std:cout<<B.size();
    return 0;
}