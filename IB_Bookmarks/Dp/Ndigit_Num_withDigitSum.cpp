#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Self explanatory, but since i was making a mistake of storing the numbers alongside, thats why i sucked in thsi too!!!
 *
 */

int mod = 1000000007;
int fun(int n, int sum, int tsum,vector <vector<int>> &dp){
    if(n<=0 and sum == tsum){
        return 1;
    }
    if(n<=0 and sum!=tsum) return 0;
    if(sum>tsum) return 0;

    if(dp[n][sum]!=-1) return dp[n][sum];

    int count = 0;
    for(int i = 0; i<=9; i++){
        count = (count+fun(n-1,sum+i,tsum,dp))%mod;
    }
    return dp[n][sum] = count%mod;
}
int solve(int n, int tsum) {
    vector <vector<int>> dp(n+2,vector<int>(tsum+2,-1));
    long long ans = 0;
    for(int i = 1; i<=9; i++){
        ans += fun(n-1,i,tsum,dp);
    }
    return ans%mod;
}