#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> um = {{'a', 0}, {'b', 0}, {'c', 0}};
        for(char c : s){
            um[c] += 1;
        }
        if(um['a']<k || um['b']<k || um['c']<k){
            return -1;
        }
        int left = 0, right = 0;
        int mid_length = 0;
        unordered_map<char, int> um2 = {{'a', 0}, {'b', 0}, {'c', 0}};
        for(int left = 0; left < s.size(); left++){
            for(int right = left; right < s.size(); right++){
                for(int i = left; i <right; i++){
                    um2[s[i]] += 1;
                }
                if((um['a'] - um2['a'])>=k && (um['b'] - um2['b'])>=k && (um['c'] - um2['c'])>=k){
                    mid_length = max(mid_length, right-left);
                }
            }
        }



        return s.size()-mid_length;
    }
};
int main(){
    Solution solution;
    string s = "aabaaaacaabc";
    int k = 2;
    return solution.takeCharacters(s, k);
}