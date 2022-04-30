#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Best time to buy and sell(Infinite Transactions allowed)

            In this problem, we can make infinite transactions. So, if we think it logically, if we buy every dip and sell at
            every peak, we surely will be the luckiest and will make the most profit. That is what we are doing in this code.
            We buy at every dip, and sell at every peak. Whenever we have a price less than previous price, which was set for
            selling the stocks, we sell them! Add to profit! And update the buy and sell both! Now they will keep updating untill
            we are at a point of time where prices start to rise again!!!
 */

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
