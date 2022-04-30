#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This problem has to be solved in O(n^2). Now i struggled a lot in this one and ended up watching this solution.
            Here, we put the difference between any two numbers and the number at which current AP ends is stored in dp.
            That is, if we have an arr = [9,4,7,2,10], then at each index, we run a loop in its front, and at each pair of
            indices, we find their difference and say that the AP that ends at index j with difference d, has a length of
            dp with difference 'd' and ending at index with which arr[j] gave difference d, ie index i. Therefore, the recurr
            ance relation becomes dp[common_diff][curr_index, j] = 1+dp[common_diff][prev_index, i]

 */

class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        int ans = 0;

        int dp[2002][arr.size()+1];
        memset(dp,-1,sizeof(dp));

        for(int i = 0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j++){
                int d = arr[j]-arr[i] + 1000;
                if(dp[d][i]!=-1) dp[d][j] = 1+dp[d][i];
                else dp[d][j] = 2;
                ans = max(ans,dp[d][j]);
            }
        }
        return ans;
    }
};