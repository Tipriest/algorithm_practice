#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
    vector<int> dist;
    double hour;
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1){
            return -1;
        }
        this->dist = dist;
        this->hour = hour;
        int maxSpeed = 0;
        for(int i = 0; i < dist.size(); i++){
            maxSpeed = ceil(max(maxSpeed, dist[i]));
        }
        if(0 != (hour - floor(hour))){
            int lasthour = dist[dist.size()-1]/(hour - floor(hour));
            maxSpeed = ceil(max(maxSpeed, lasthour));
        }
        
        
        int left = 1, right = maxSpeed;
        while(left<=right){
            int mid = (left+right)/2;
            if(satisfy(mid)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        if(right-1>-1 && !satisfy(right-1) && satisfy(right)){
            return right;
        }else{
            return right+1;
        }
        return right;

    }
    bool satisfy(int speed){
        double result = 0;
        for(int i = 0; i < dist.size()-1; i++){
            result += ceil((double)dist[i]/speed);
        }
        result += (double)dist[dist.size()-1]/speed;
        return this->hour>=result;
    }

};

// int main(){
//     Solution solution;
//     vector<int> dist = {1, 1, 100000};
//     double hour = 2.01;
//     return solution.minSpeedOnTime(dist, hour);
// }