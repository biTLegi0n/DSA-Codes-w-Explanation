#include <bits/stdc++.h>
using namespace std;

/**
 * @brief In these type of questions, finding exact k unique elements is a bit difficult work, therefore, we find subarrays with atmost
 *        k elements and subarray with atmost k-1 element, and then we subtract atmost(k)-atmost(k-1) to get exact k unique elements. 
 *        To find atmost(k) elements, we use two pointers, and hashing. 
 * 
 */

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // In such questions, directly finding exactly k different intergers is a bit difficult, therefore
        // we solve it by subtracting subarrays with atmost k-1 elements out of subarrays having atmost k elem. 
        return fun(nums,k)-fun(nums,k-1);
    }
protected:
    int fun(vector <int>&nums, int k){
        int low = 0, high = 0, count = 0, subarray=0;
        unordered_map <int,int> mp;
        bool flag = true;
        while(low<=high and high<nums.size()){
            if(flag) mp[nums[high]]++;
            
            if(mp.size()<=k) subarray += high-low+1;
            
            if(mp.size()>k){
                mp[nums[low]]--;
                if(mp[nums[low]]==0) mp.erase(nums[low]), count--;
                low++;
                flag = false;
            }
            else high++, flag = true;
            
        }
        return subarray;
    }
};