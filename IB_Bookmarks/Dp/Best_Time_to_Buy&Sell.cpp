#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   As we move ahead in days, we look for the day having minimum price and then check the answer by selling it everyday
 *          after buying. Since only one transaction is allowed, we dont need to do anything else.
 */

int maxProfit(const vector<int> &arr) {
    int buy = INT_MAX, profit = 0;
    for(int i = 0; i<arr.size(); i++){
        buy = min(buy,arr[i]);
        profit = max(profit,arr[i]-buy);
    }
    return profit;
}
