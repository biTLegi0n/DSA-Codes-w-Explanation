#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
/*
    Approach : Another simple application of UnBounded knapsack. We only need to take care of the initialization in this.
                we initialize the 0th row with INF-1 where INF is INT_MAX. :: -1 because we are adding dp[i][j - coins[i-1]] + "1"
                Adding this one in INT_MAX could cause an overflow, because we cannot hold that much in int.
                    - Then we simply need to modify the formula a little bit. As we need minimum, thus we write min and with every 
                      coin, which we are including, we add 1 which indicated that we are using 1 more coin to achieve this goal
                - Atlast we also need to see the returning method, as if INT_MAX - 1 is returned, that means there is no way to 
                    achieve the sum we want from the given coins :() 
*/

// Space optimized
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        memset(dp,10004,sizeof(dp));
        dp[0] = 0;

        // Since this was an unbounded knapsack, therefore, we have to start j from 0 and move towards amoount. If it were bounded, we start 
        // from amount and move towards 0. 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=amount; j++){
                if(j>=coins[i])
                    dp[j] = min(dp[j], 1+dp[j-coins[i]]);
            }
        }
        return dp[amount]>=10004 ? -1 : dp[amount];
    }
};

int min_coins(int n, int sum, int coins[])
{
    int dp[n+1][sum+1];

    // We initialize first row with INF as it is not possible to make any sum (except 0) with zero coins, so we consider INF coins
    for(int j = 0; j<=sum; j++)
        dp[0][j] = INF-1; //(INF - 1 to avoid overflow)
    for(int i = 1; i<=n; i++)
        dp[i][0] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(coins[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else    
                // We add 1 with every coin we consider because we are storing the number of coins needed t0 achieve sum 'j'
                dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
        }
    }
    // This condition means that the sum is unachievable from the coins given to us
    if(dp[n][sum] >= INF - 1)
        return -1;
    else
    return dp[n][sum];
}