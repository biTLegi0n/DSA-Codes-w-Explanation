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
    Approach : This problem is a direct implementation of UnBounded knapsack. We just need to modify the formula of 01 knapsack
                by the fact that we can reconsider the choosen item/length. Thus, we change dp[i-1][j - len[i-1]] to dp[i][j-len[i-1]]
*/

// n -> no of elements in len[] array ; length -> The length we want (just like Weight in 01 Knapsack) 
int rod_cutting(int n, int price[], int len[], int length){
    // n is downwards and length is right
    int dp[n+1][length + 1];

    for(int i = 0; i<=n; i++)
        dp[i][0] = 0;
    for(int i = 0; i<=length; i++)
        dp[0][i] = 0;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= length; j++){
            if(len[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else    
            // dp[i][j - len[i-1]] means that we considered that element and still stays on it while next iteration makes a choice.
                dp[i][j] = max(price[i-1] + dp[i][j - len[i-1]] ,  dp[i-1][j]);
        }
    }
    return dp[n][length];
}       

int main()
{
    int n, length;      // Number of elements in lengths array i.e array telling us 
    cout<<"Number of allowed cuts : ";
    cin>>n;
    cout<<"Enter the length of rod : ";
    cin>>length;
    int price[n], len[n];
    cout<<"Enter the allowed cuts";
    for(int i = 0; i<n; i++)
        cin>>len[i];
    cout<<"Enter the Prices : ";
    for(int i = 0; i<n; i++)
        cin>>price[i];
    
    cout<<rod_cutting(n, price, len, length)<<"\n";
    
}