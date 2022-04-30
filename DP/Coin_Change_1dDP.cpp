#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This problem has already been implemented using 2d in DP section. Here, i implemented it with 1D dp. There aren't
            many changes to the problem. We just make a dp array with sum+1 size, and in place where we used to initialize the
            whole first coloumn with 1, we initialize first element with 1. After that, the story is all the same. If arr[i]>j
            we continue, else dp[j] += dp[j-arr[i]]. Thatsall!

 */

int coinchange2(vector<int> &arr, int sum) {
    int n = arr.size();

    vector <long long> dp(sum+1,0);
    dp[0] = 1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<=sum; j++){
            if(arr[i]>j) continue;
            dp[j] += dp[j-arr[i]];
        }
    }

    return dp[sum];
}
