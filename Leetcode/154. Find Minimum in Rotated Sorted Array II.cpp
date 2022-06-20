#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In rotated sorted array, which has duplicates, finding a duplicate is relatively difficult. But what we can do is, we
            skip the duplicates from both sides. We check that in left side, if numbers are repeating, we keep updating low,
            similiarly, from high too. Then our low and high stand at points where their duplicates have been skipped. Now,
            there could be more duplicates in between low and high range, but there isnt any duplicate at low and high indices.
            Rest algorithm is just the same, NO CHANGE.

 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int low = 0, high = nums.size()-1, ans = INT_MAX;
        while(low < high){
            while(low<high and nums[low] == nums[low+1]) low++;
            while(low<high and nums[high] == nums[high-1]) high--;

            int mid = low + (high - low)/2;

            if(nums[mid]>=nums[low]){
                if(nums[mid]<nums[high]) high = mid;
                else low = mid+1;
            }
            else high = mid;
        }
        return nums[high];
    }
};