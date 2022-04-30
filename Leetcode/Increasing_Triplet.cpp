#include <bits/stdc++.h>
using namespace std;

// It was constrained that we have to do this in O(N) and O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<2)
            return false;
        
        int first = INT_MAX, sec = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            // If num is smaller than first
            if(nums[i] <= first)
                first = nums[i];
            else
            // If num is smaller than second and greater than first
            if(nums[i] <= sec)
                sec = nums[i];
            else{
            // If num is greater than both first and second
                return true;
            }
        }
        return false;
    }
};