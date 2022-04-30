#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this problem, we only need to run kNapsack n times for each friend and since we need to find the minimum cost,
            we initialize with INT_MAX
 */

int knapsack(int weight, const vector <int>&arr, const vector <int>&cost){
    int n = arr.size();
    long long dp[n+1][weight+1];

    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    for(int j = 0; j<=weight; j++) dp[0][j] = INT_MAX-1;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=weight; j++){
            if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i][j-arr[i-1]] + cost[i-1], dp[i-1][j]);
        }
    }
    return dp[n][weight];
}
int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int cost = 0;
    for(int i = 0; i<A.size(); i++)
        cost += knapsack(A[i],B,C);
    return cost;
}
