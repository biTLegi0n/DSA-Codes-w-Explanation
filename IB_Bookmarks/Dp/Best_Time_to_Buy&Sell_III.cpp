#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Best Time to buy and sell(atmost 2 transactions allowed) Link https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

  @a This question is a simple and straightforward. OK! So, we find the maximum profit we can gain by selling something today! So, we store 
     the possible maximum profit we can have till today by selling something today in a prefix array.
     Similiarly, we will store the maximum profit we can gain so far by buying something today. 
     This may sound a little confusing but wait! Let me clearly explain. 
     So, this prefix array is actually an array that is storing the maximum profit so far, if we were required to sell something today.
     Now, to do so, we maintaing a maximum profit variable and a buy variable, that would store the minimum buying price for any stock. 
     Now, since we were asked to perform atmost 2 transactions, therefore, doing this prefix will take 1 transaction. Similiarly, the
     suffix array will store the maximum profit so far if we were required to buy on that day. Here, we will maintain a sell variable that
     will store the maximum selling price so far so that we can find the maximum profit we can gain by buying a stock today.

     At the end, we just loop over these two arrays simultaneously and our answer will be the maximum sum of the elements of both ararys at 
     same index. 

     Note that for suffix, we have to start from back because we are buying on a day, so we need to store the maximum selling price for a stock
     and if we are selling, then that means, we have already bought something. So, to store the maximum selling price, we must start from last
     coz, if we start from first, then we'll have to loop in front of a day to find the best selling day, which is obviously the day having max
     price. Instead of that, we just start from last, maintaing that max price.   


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