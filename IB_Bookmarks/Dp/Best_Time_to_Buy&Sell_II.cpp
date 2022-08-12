#include <bits/stdc++.h>
using namespace std;

// Later is a code using one for loop only but below is the template for all buy and sell problems

// Flag is a variable that decides the state, whether we are buying or selling at ith day. Now we can modify this into any of the 
// problem's solution. Like, for atmost k transactions, we pass another argument k to the function and store it in dp. 
class Solution {
public:
    int dp[30004][2];
    int answer(vector<int>&prices,int i,bool f){
      if(i>=prices.size())
          return 0;
        if(dp[i][f]!=-1)
            return dp[i][f];
        // If f==0, means we can buy. AND If we buy, we reduce its cost from total profit. 
        if(f==0){
            int x=answer(prices,i+1,f^1)-prices[i];
            int y=answer(prices,i+1,f);
            return  dp[i][f]= max(x,y);
            
        }
        // It means we can sell.
        int x=answer(prices,i+1,f^1)+prices[i];
        int y=answer(prices,i+1,f);
        return dp[i][f]=max(x,y);
            
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return answer(prices,0,0);
    }
};


/*
  @brief    Best time to buy and sell(Infinite Transactions allowed)

            In this problem, we can make infinite transactions. So, if we think it logically, if we buy every dip and sell at
            every peak, we surely will be the luckiest and will make the most profit. That is what we are doing in this code.
            We buy at every dip, and sell at every peak. Whenever we have a price less than previous price, which was set for
            selling the stocks, we sell them! Add to profit! And update the buy and sell both! Now they will keep updating untill
            we are at a point of time where prices start to rise again!!!
 

int maxProfit(const vector<int> &arr) {
    if(arr.empty()) return 0;

    int buy=arr[0], sell = arr[0], prev = sell, profit = 0;
    for(int i = 1; i<arr.size(); i++){
        if(arr[i]<sell){
            profit += sell-buy;
            buy = arr[i];
            sell = arr[i];
        }
        else{
            sell = arr[i];
        }
    }
    profit += sell-buy;
    return profit;
}
*/