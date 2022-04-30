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
    Approach: In this question, we are asked to divide the array in such a way that the difference between the two subsets is minimum.
              We first find whether a particular subset with particular sum exist or not. We check these possibilities in the last row
              Then, we check for the minimum in the subsets that exists. We check which one of them has the minimum diffrence.
              V assume that S1 < S2     
*/

int Min_Partition(int n, int a[]){

    int TotalSum = 0;
    for(int i = 0; i<n; i++)
        TotalSum += a[i];
    
    bool dp[n+1][TotalSum+1];
    
    for(int i = 0; i<=n; i++)
	    dp[i][0] = true;
	    
	for(int j = 1; j<=TotalSum; j++)
        dp[0][j] = false;
	   
	for(int i = 1; i<=n; i++){
        for(int j = 1; j<=TotalSum; j++){
	        if(a[i-1] > j)
	            dp[i][j] = dp[i-1][j];
	        else
                dp[i][j] = (dp[i-1][j - a[i-1]] || dp[i-1][j]);
        }
	}
	    
	int mini = INT_MAX;
	    
	for(int j = 0; j<=TotalSum/2; j++){
	    if(dp[n][j] == true){
            if(TotalSum - 2*j < mini)       // (TotalSum - j) - j => Difference of sum of two subsets
	            mini = TotalSum - 2*j;
        }
    }
	    
    return mini;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];
    
    cout<<Min_Partition(n, a);
}