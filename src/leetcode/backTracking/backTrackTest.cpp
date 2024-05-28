#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        s_m = m;
        s_n = n;
        backTracking(0, 0);
        return res;

    }
    void backTracking(int x, int y){
        //搜索超出界限，返回
        if(x>s_m || y>s_n){
            return;
        }
        if(x == s_m && y == s_n){
            res += 1;
            return;
        }
        //在同一层分别尝试向下右搜索，不会有走过的路，不需要减枝处理
        for(int i = 0; i < 2; i++){
            if(0 == i){
                backTracking(x+1, y);
            }else if(1 == i){
                backTracking(x, y+1);
            }
        }
    }
private:
    int s_m, s_n;
    int res = 0;
};
int main(int argc, char** argv){
    Solution solution;
    
    int result = solution.uniquePaths(3, 2);
    cout<<"result = "<< result <<endl;
    return 0;
}