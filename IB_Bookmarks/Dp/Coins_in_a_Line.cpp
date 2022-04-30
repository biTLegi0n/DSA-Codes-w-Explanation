#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This same question was done in pepcoding, named The optimal Game Strategy. Now, the main part in this question is
            the fact that the opponent will also choose optimally. So, what we do is that at both fronts, we make our choices.
            We choose left side, and then say that choose the minimum of the two, ie if opponent also chooses left(i+2) or if
            he chooses right(i+1,j-1). We take minimum of these two which denotes that the opponent has chosen whats best for him
            Similiarly we do this when we choose right. After making both the choices, we store the maximum out of these two
            in dp.

 */

int dp[505][505];
int fun(int i, int j, vector <int>&arr){
    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int chose1 = arr[i]+min(fun(i+2,j,arr),fun(i+1,j-1,arr));
    int chose2 = arr[j]+min(fun(i,j-2,arr),fun(i+1,j-1,arr));

    return dp[i][j] = max(chose1,chose2);
}
int maxcoin(vector<int> &arr) {
    memset(dp,-1,sizeof(dp));
    return fun(0,arr.size()-1,arr);
}
