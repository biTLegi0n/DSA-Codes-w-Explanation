#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Best Time to buy and sell(atmost 2 transactions allowed) Link https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

  @a The approach to solve this problem is straightforward. We find a day where the best buy and best sell take place. We know
     that best for best sell, we follow the base versions' algorithm, where we find the minimum price in past and check everyday
     for the profit and record the maximum profit. Here, we store that maximum profit TILL NOW in a array named prefix. Now,
     prefix contains the maximum profit till now for best sell. Similiarly, we do something like this for best buy. Now, best
     sell means the profit that we would have if we have to sell the stock on current day. Now to find this, we find the highest
     sell price of the stock till now, and check for profit everyday. @note that we are not going backwards in time, but in array
     that means, we are buying before selling.
     - Best buy means the profit we will gain if we have to buy the stock on current day!!
     - Best sell means the profit we will gain if we have to sell the stock on current day!!


 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Since at most two transactions are allowed, therefore run the "atmost 1 transaction" algorithm 2 times,
        // Once from front and then from back and one for best buy and another for best sell
        vector <int> prefix(prices.size(),0), suffix(prices.size(),0);

        int buy = INT_MAX, profit = 0;
        for(int i = 0; i<prices.size(); i++){
            buy = min(buy,prices[i]);
            profit = max(profit,prices[i]-buy);
            prefix[i] = profit;
        }
        int sell = INT_MIN;
        profit = 0;
        for(int i = prices.size()-1; i>=0; i--){
            sell = max(sell,prices[i]);
            profit = max(profit,sell-prices[i]);
            suffix[i] = profit;
        }

        int maxprofit = INT_MIN;
        for(int i = 0; i<prices.size(); i++){
            maxprofit = max(maxprofit, prefix[i]+suffix[i]);
        }
        return maxprofit;
    }
};