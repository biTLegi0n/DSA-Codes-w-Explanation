#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In questions like these where we have to count the number of subarrays, which includes single numbers as well as
            subarrays, we always prefer to go with twi oiubter sliding window concept and the number of subarray is always
            found with high-low+1. This includes the single element as well as subarray between high and low.

 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1, count = 0;
        int low = 0, high = 0;
        while(low<=high and high<nums.size()){
            prod *= nums[high];

            while(low<=high and prod >= k){
                prod /= nums[low++];
            }
            count += high - low + 1;
            high++;
        }
        return count;
    }
};