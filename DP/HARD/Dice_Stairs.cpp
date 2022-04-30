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
    NOTE: There are some things to note, This ques and a ques of stairs (Link below), might seem similiar to counting all possible 
          subsets(Or coin_change_MaxWays) but there is a major difference, in counting subsets problem, if we have to count all subsets that sum up to 3
          we will have {1, 1, 1}, {1, 2} & {3}, while in stairs_dice problems, while in problems like dice and stairs, we have to 
          consider subsets {1, 1, 1,}, {1, 2}, {2, 1} & {3} which turns the tables.

    --> In such type of questions where we are already given some fixed moves, we approach them by 1D dp table and just define the
        formula according to those fixed moves. For ex, if we are told that we have to reach nth stair using on jump of 1 and 2 stairs
        Then we'd write something like dp[n] = dp[n-1] + dp[n-2] :: Max, Min or + according to need
        Similiarly, if we are asked to find all possible ways to have a sum using a dice, then we have only 6 possibke values of dice
        so we approach that using this same algo that dp[sum] = dp[sum-1] + dp[sum-2] + dp[sum-3] + dp[sum-4] ..... dp[sum-6]

    MOST IMP NOTE: If in any subsets ques, {1, 2} & {2, 1} are considered as two different subsets (like {1, 2, 3}, {1, 3, 2}, {3, 1, 2}, {2, 1, 3})
                    Then we use this Dice/Stairs approach using 1D dp and considering only some fixed moves. We set dp[n] + = dp[n-arr[i]] ......
*/
int dice_comb(int n){
    int dp[n+1];

    //memset(dp, 1, sizeof(dp));
    for(int i = 1; i<=n; i++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=6; j++)
        // Instead of writing dp[sum - 1, 2, 3] again n ahain, we put a loop for those and if (i>j), we made our call
            if(i >= j)
                dp[i] = dp[i] + dp[i-j];
    }
    for(int i = 0; i<=n; i++)
        cout<<dp[i]<<" ";
    return dp[n];
}

int main()
{
    int sum;
    cin>>sum;

    cout<<"Total number of Combinations for sum "<<sum<<" are : "<<dice_comb(sum);
}