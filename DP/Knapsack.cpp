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

int dp_rec[1005][1005];
int dp_tab[1005][1005];

// This function shows the implementation of Knapsack using Recursion and Memoization
int knapsack_rec(int n, int w, int val[], int wt[]){
    if(n == 0 || w <= 0)
        return 0;
    
    if(dp_rec[n][w] != -1)
    //  If we have already calculated the answer...
        return dp_rec[n][w];
            
    if(wt[n-1] > w)
    //  if the size of item is larger than the knapsack's size, Then we have no choice, we ignnore this element
        return dp_rec[n][w] = knapsack_rec(n-1, w, val, wt);
    else
    //  Since the indexing is Zero based, therefore, we take v[n-1] & wt[n-1] because if we would have taken val[n] in this case,
    // It would have returned 0 without considering the value of first item...
    // Since the item's weight is less than w, we make a choice :)
        return dp_rec[n][w] = max(val[n-1] + knapsack_rec(n-1, w-wt[n-1], val, wt), knapsack_rec(n-1, w, val, wt));
}


//This function will show the implementation of Knapsack using Tabulation Method (or) Bottom Up Method
void knapsack_tab(int n, int w, int val[], int wt[]){
//NOTE : i(downwards, shows number of elements to be taken) 
//     : j(right, shows all the possible weights upto 'w')
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=w; j++){
            // We fill the first row and coloumn by 0, which depicts the base case of recursion
            if(i == 0 || j == 0)
                dp_tab[i][j] = 0;
            else{    
                if(wt[i-1] <= j)
                // We only compare if wt[i-1]( i-1 because we have zero based indexing) is less than 'w'
                    dp_tab[i][j] = max(val[i-1] + dp_tab[i-1][j - wt[i-1]], dp_tab[i-1][j]);
                else
                    dp_tab[i][j] = dp_tab[i-1][j];
            }
        }
    }
}

int main()
{
    //FAST;

    int n, w;
    cin>>n>>w;

    int val[n], wt[n];
    cout<<"Enter the ValuE array : ";
    for(int i = 0; i<n; i++)
        cin>>val[i];
    cout<<"Enter the WeighT array : ";
    for(int i = 0; i<n; i++)
        cin>>wt[i];
    
    memset(dp_rec, -1, sizeof(dp_rec));
    int ans = knapsack_rec(n, w, val, wt);
    cout<<"Answer from Memoization : "<<ans<<"\n";
    knapsack_tab(n, w, val, wt);
    cout<<"Answer from Top Down/ Tabulation : "<<dp_tab[n][w]<<"\n";
    // cout<<knapsack_rec(n, w, val, wt);
}