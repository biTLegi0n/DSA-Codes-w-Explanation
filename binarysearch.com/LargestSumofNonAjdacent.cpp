#include <bits/stdc++.h>
using namespace std;

/**
  @brief    wE ARE maintaing only two variables to store the choices. Do note that this is DP with no space. So what we are doing is we
            store the max till now, including the current character in 'inc', and excluding the current character in 'exc'....
            Note that previous include can now be exc and previous exc can be used to calculate current includE. This is because when we 
            include current element, the the exc has the maximum value so far excluding the last element, because the max after including the 
            last element will be updated in exc after this step. So, we can easily find the answer in O(n). 
*/

int solve(vector<int>& nums) {
    if(nums.empty()) return 0;
    int inc = max(nums[0],0), exc = 0;
    for(int i = 1; i<nums.size(); i++){
        int temp = inc;
        inc = max(inc, exc+nums[i]);
        exc = temp;
    }
    return inc;
}