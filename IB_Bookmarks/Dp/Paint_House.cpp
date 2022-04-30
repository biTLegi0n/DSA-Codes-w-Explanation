#include <bits/stdc++.h>
using namespace std;

int fun(int col, int i, vector<vector<int>>&cost, vector<vector<int>>&dp){
    if(i>=cost.size()) return 0;

    if(dp[i][col]!=-1) return dp[i][col];

    int c1, c2;
    if(col==0) c1 = 1, c2 = 2;
    else
    if(col==1) c1 = 0, c2 = 2;
    else c1 = 0, c2 = 1;

    int res = min(fun(c1,i+1,cost,dp),fun(c2,i+1,cost,dp));
    return dp[i][col] = cost[i][col] + res;
}
int solve(vector<vector<int> > &A) {
    vector <vector <int>> dp(A.size(),vector<int>(A[0].size(),-1));
    int n = A.size();
    return min(fun(0,0,A,dp),min(fun(1,0,A,dp),fun(2,0,A,dp)));
}
