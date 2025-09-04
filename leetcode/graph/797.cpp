#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    int Find(vector<int> parent, int index){
        if(parent[index] == index){
            return index;
        }
        return Find(parent, parent[index]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n+1, 0);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(const auto& edge : edges){
            if(Find(parent, edge[0]) == Find(parent, edge[1])){
                continue;
            }else{
                parent[Find(parent, edge[0])] = Find(parent, edge[1]);
            }
            if(Find(parent, source) == Find(parent, destination)){
                return true;
            }
        }

        return false;
    }
};
int main(int argc, char ** argv){
    Solution solution;
    vector<vector<int>> edges;
    edges = {{0,1}, {1,2}, {2,0}};
    solution.validPath(3, edges, 0, 2);
    return 0;
}
