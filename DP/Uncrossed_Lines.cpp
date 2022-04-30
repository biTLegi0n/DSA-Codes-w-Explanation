#include<bits/stdc++.h>
#define vi vector <int>
#define vl vector <long long>
#define vc vector <char>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
/*  
    Approach: We approach the following question in LCS format. As we need to find the number of maximum uncrossing lines, we can 
              do so by following idea from LCS. We take one element from 1st vector, and then calculate the answer, then we check 
              the effect of adding elements in this.(NOTE: This is what we do in case of finding LCS, we compare the whole 2nd string 
              with one character) Adding element will affect only in one of the following 2 ways : 
              1. if the added element is same to that of that one element, we add 1 to dp[i-1][j-1](as we will move the pointer in both vectors)
              2. If the added element is not same, then we will take the maximum of dp[i-1][j] & dp[i][j-1]
            
            We should know how this works? We take one single character from one array/string which is 1st row/coloum of dp table, and then
            we check the whole another vec/string with that one character and +1 in dp[][] if we find a match. Als0, we initialize the 
            first row and coloumn with 0
*/
int UncrossedLines(vi &a, vi &b){
    int m = a.size();
    int n = b.size();

    int dp[m+1][n+1];

    for(int i = 0; i<=m; i++)
        dp[i][0] = 0;
    for(int j = 0; j<=n; j++)
        dp[0][j] = 0;
    
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
//   FAST;
    vi a, b;
    
    int m, n;
    cin>>m>>n;
    for(int i = 0; i<m; i++){
        int k;
        cin>>k;
        a.pb(k);
    }
    for(int i = 0; i<n; i++){
        int k;
        cin>>k;
        b.pb(k);
    }

    cout<<"The maximum number of uncrossed lines are : "<<UncrossedLines(a, b)<<"\n";

}