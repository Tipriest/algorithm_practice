#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


int main() {
   int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
   vector<int> cost(a, a + sizeof(a) / sizeof(int));
   for(int i = 0; i < cost.size(); i++){
   cout<<" "<<cost[i];
   }
   cout<<endl;
   int i = 0;
   while(true){
      cout<<i<< " You are Best!"<<endl;
      i ++;
   }
   return 0;
}