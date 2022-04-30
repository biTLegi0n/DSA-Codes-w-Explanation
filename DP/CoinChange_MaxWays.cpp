#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF 99999999
#define MIN -99999999
#define pb push_back
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

/*
    Approach : This problem is another application of UnBounded knapsack where you need to achieve a sum using some coins
                and the twist is that you can use one coin any number of times and you have to return the max no of ways to achieve that
                Does this sounds like counting subsets, a kind of subset sum problem, isn't it? Well it is subset sum with a minor change
                    - counting subsets as we have to find the number of ways to achieve a particular sum :)
*/

ll int coin_change(int coins[], int n, int sum){
    ll dp[n+1][sum + 1];

    // Initialization is same as in counting sum's code
    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;
    for(int i = 1; i<=sum; i++)
        dp[0][i] = 0;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(coins[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
            // Only this thing is changed in the code of Counting subsets having a sum    
                dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];  // dp[i] instead of dp[i-1]
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    cout<<"Enter the number of coins : ";
    cin>>n;
    cout<<"Enter the sum to achieve : ";
    cin>>sum;
    int coins[n];
    cout<<"Enter the available coins : ";
    for(int i = 0; i<n; i++)
        cin>>coins[i];

    cout<<coin_change(coins, n, sum)<<"\n";    

}