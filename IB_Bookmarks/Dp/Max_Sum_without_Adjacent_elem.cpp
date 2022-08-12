#include <bits/stdc++.h>
using namespace std;

/**
  @brief    No two adjacent elements should be taken ( Adjacent is defined by horizontally, vertically, diagonally ).
            so suppose we have 2 * N list :

            1 |  2  |  3  | 4
            2 |  3  |  4  | 5

            Now suppose we choose 2, then we can't choose the element just above it 1,  the element next it 3, or the element
            diagonally opposite. In other words, if we are on (x, y), then if we choose (x, y), we can't choose (x + 1, y),
            (x, y + 1) and (x + 1, y + 1).

            iN CASE, where there are only one coloumn, the max of the two is our answer.Thus, we initialize the first two elements
            of dp to the max of those four and then we move ahead adding up the max till now with the max of current coloumn

 */

// Recursive Version
int fun(int i, vector<vector<int>>&mat,vector<int>&dp){
    if(i>=mat[0].size()) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i] = max(max(mat[0][i],mat[1][i]) + fun(i+2,mat,dp), fun(i+1,mat,dp));
}
int adjacent(vector<vector<int> > &A) {
    vector<int>dp(A[0].size(),-1);
    return fun(0,A,dp);
}

// Tabulation
int adjacent(vector<vector<int> > &arr) {
    int maxi = INT_MIN,ans = INT_MIN;
    vector <int> dp(arr[0].size(),-1);
    dp[0] = max(arr[0][0],arr[1][0]);
    dp[1] = max(dp[0],max(arr[0][1],arr[1][1]));

    for(int i = 2; i<arr[0].size(); i++){
        maxi = max(arr[0][i],arr[1][i]);

        dp[i] = max(maxi+dp[i-2],dp[i-1]);
    }
    return dp[arr[0].size()-1];
}
