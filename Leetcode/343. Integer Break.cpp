#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This problem was realllly easy. I wasted alot of time overthinking. We just need to maximize the product. Now, we dont 
            have to maintain a fixed number of numbers we have to use for the sum, so we just focus on the product. We will use the
            same include-exclude method here. We make an array of numbers from 1-(n-1) and then, we include all those numbers whose sum
            is less than n, and try to maximize the product. As simple as that. if the sum crosses n, we return 0, if sum==n, we return
            1. 
  
 */

class Solution {
public:
    int integerBreak(int n) {
        vector <int> arr;
        for(int i = 1; i<=n-1; i++) arr.push_back(i);
        vector <vector <int>> dp(arr.size(), vector <int>(n+1,-1));
        return fun(0,n,0,arr,dp);
    }
protected:
    int fun(int idx, int n, int sum, vector<int>&arr,vector <vector<int>>&dp){
        if(sum == n) return 1;
        if(sum>n) return 0;
        if(idx>=arr.size()) return 0;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum]; 
        
        int inc = arr[idx]*fun(idx,n,sum+arr[idx],arr,dp);
        int exc = fun(idx+1,n,sum,arr,dp);
        
        return dp[idx][sum] = max(inc,exc);
    }
};