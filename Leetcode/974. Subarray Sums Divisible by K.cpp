#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   We need to find the subarrays with sum divisible by k. Ok! If sum is divisible by k, then its modulo with k will be 0. 
 *          So, instead of hashing sum, we now hash modulo and since arrays also contains negartive numbers, therefore, we do 
 *          ((sum%k)+k)%k. We do this because sum%k -> negative + k => must be a positive %k = real mod
 * 
 */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <long long,int> mp;
        long long sum = 0,count=0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(sum%k==0) count++;
            if(mp.find(((sum%k)+k)%k)!=mp.end()) count += mp[((sum%k)+k)%k];
            
            mp[((sum%k)+k)%k]++;
        }
        return count;
    }
};