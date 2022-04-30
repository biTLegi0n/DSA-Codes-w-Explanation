#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This problem is a combination of target sum and Count minimum coins. Here we need to count the minimum number
            of elements to be flipped to reduce the sum to as minimum as possible. Thus we do the following.
            We find the minimum number of elements required to achieve a particular sum. Rest is the same concept that we must
            know about how to find two subsets whose sum difference is minimum

 */

int solve(const vector<int> &arr) {
    int total = 0;
    for(auto u : arr) total += u;

    int sum = total/2, n = arr.size();

    long long dp[n+1][sum+1];
    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    for(int j = 1; j<=sum; j++) dp[0][j] = INT_MAX-1;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(arr[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-arr[i-1]]+1);
        }
    }

    for(int j = sum; j>=0; j--){
        if(dp[n][j]<INT_MAX-1) return dp[n][j];
    }
    return 0;
}
