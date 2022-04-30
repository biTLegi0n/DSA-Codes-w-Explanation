#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Since greedy approach wont work here, we have to check for every adjacent pair of elements and where we have to
            check with every element, we go with MCM. Here, we run a loop between i and j, just like other MCM, and each time
            we check with idx and idx+1, we merge these two, thus we add their cost and call their left and right functions
            respectively. Their cost can be seen as the sum of that [i,j] segment because that is what it will be ultimately.
            [1,2,3,4] here the cost depends totally on i and j. The cost of merging elements in [i,j] is sum of all elements
            of [i,j]. If not getting this, solve some examples on paper. Then, when we have the cost of merging idx and idx+1
            we call two recusive functions on left, ie [i,idx] and right [idx+1,j].
            Then just like mcm, we calculate the minimum value of answer.
 */

int fun(int i, int j, vector <int>&arr, int sum, vector <vector <int>>&dp){
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int lsum = 0, ans = INT_MAX;
    for(int idx = i; idx<j; idx++){
        lsum += arr[idx];
        int count = sum + fun(i,idx,arr,lsum,dp) + fun(idx+1,j,arr,sum-lsum,dp);
        ans = min(ans,count);
    }
    return dp[i][j] = ans;
}
int solve(vector<int> &A) {
    int sum = 0;
    for(auto u : A) sum += u;
    vector <vector <int>> dp(A.size(), vector <int>(A.size(),-1));

    return fun(0,A.size()-1,A,sum,dp);
}
