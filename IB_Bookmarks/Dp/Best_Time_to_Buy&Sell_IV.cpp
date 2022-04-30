#include <bits/stdc++.h>
using namespace std;

/**
  @brief In this problem, we were allowed to make atmost k transactions only. Well, in that case scenerio, a tabular dp
         could fir perfectly well. So what we do here is to compare two conditions for dp[i][j], where i is transaction and
         j is the day on which we are comparing :
         - if we have already made i transactions before jth day, then we cannot make more transactions and previous profit
           will remain as it is.
         - In case we have not made i transaction till the day, then we go in past for i-1 transactions, because we have made them
           and check for the maximum profit that this current day can give us. To do so, we go on all the days before jth day and
           check for the max profit. And at last, we compare the dp[i][j-1] and dp[i-1][all days before j] profit.

        Note that we are not doing anything like comparing the left and top left, because top left does not always have the maximum
        for above row. Why so? Consider an example where the days have prices as [... 1, 3, 4, ...]. Now, for the day having price
        = 3, lets say the max will be 3-1 = 2. Now its dp contains 2. Now, if we are at next row, checking for 4, then its top left
        will be having 2, which is not its maximum but 3s maximum. So, taking just only 2, will give us WA. thatswhy we run a loop
        on every day before 4, and assuming 1 to be the minimum price before 4, we will now have 3 as the maximum profit and not 2.

  @note In comments below this code, i have written a space optimized code for the same problem. Not my code, btw.
        But i can say that in my code, i only need to add the modulo feature for rows ie transactions and it will work just fine
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;

        int dp[k+1][prices.size()];
        //If we have only one stock, then no. of trnsc wont change anything
        for(int i = 0; i<=k; i++) dp[i][0] = 0;
        //If we are allowed to make 0 trnsc, then stocks wont change anything
        for(int j = 0; j<prices.size(); j++) dp[0][j] = 0;

        for(int i = 1; i<=k; i++){
            for(int j = 1; j<prices.size(); j++){
                dp[i][j] = dp[i][j-1];
                for(int pd = 0; pd<j; pd++){
                    dp[i][j] = max(dp[i][j],(prices[j]-prices[pd])+dp[i-1][pd]);
                }
            }
        }
        return dp[k][prices.size()-1];
    }
};
/*
int maxProfit_all(vector<int> &prices) {
    int n = prices.size();
    int sum = 0;
    for(int i = 1;i < n;i++){
        if(prices[i] > prices[i-1]){
            sum += prices[i] - prices[i-1];
        }
    }
    return sum;
}
int Solution::solve(vector<int> &prices, int k) {
    int n = prices.size();
    if(k >= n/2){
        return maxProfit_all(prices);
    }
    int dp[2][n+1];
    memset(dp,0,sizeof(dp));
    for(int t = 1; t <= k; t++){
        int cur_max = INT_MIN;
        dp[t%2][0] = 0;
        for(int i = 0; i < n; i++){
            dp[t%2][i+1] = max(dp[(t+1)%2][i+1],max(dp[t%2][i],prices[i] + cur_max));
            cur_max = max(cur_max,dp[(t+1)%2][i] - prices[i]);
        }
    }
    return dp[k%2][n];
}


*/