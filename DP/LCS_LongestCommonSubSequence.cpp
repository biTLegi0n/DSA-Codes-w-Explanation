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

int dp_rec[1000][1000];

/*
    Approach : LCS is a whole new type of dp. Here, we dont have any kind of formula but this one is still very easy. 
               We follow a simple rule, that if the last characters we are matching are same, then we increase the length
               by 1 and move ahead in both the string else we make our gamble by moving ahead in one string and comparing 
               the maximum result out of that. i.e max( lcs(m-1, n), lcs(m, n-1) ) 
*/

// Space optimized
int lcs(string &X, string &Y)
{
    int m = X.length(), n = Y.length();
 
    int L[2][n + 1];
    // Binary index, used to index current row and previous row.
    bool bi;
    for (int i = 0; i <= m; i++)
    {
        bi = i & 1;
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;
            else if (X[i-1] == Y[j-1])
                 L[bi][j] = L[1 - bi][j - 1] + 1; 
            else
                L[bi][j] = max(L[1 - bi][j],L[bi][j - 1]);
        }
    }
    return L[bi][n];
}

int lcs_rec(string s1, string s2, int m, int n){
    
    // This is the BasECase, when length of both strings is 0, we have 0 characters in common. So Length of LCS = 0
    if(m == 0 || n == 0)
        return 0;

    if(dp_rec[m][n] != -1)
        return dp_rec[m][n];
    else
    // If last characters are same, we move ahead in both strings
    if(s1[m] == s2[n])
        return dp_rec[m][n] = (1 + lcs_rec(s1, s2, m-1, n-1));
    else
    // If not same, we make our choices by moving in one and staying in other    
        return dp_rec[m][n] = max(lcs_rec(s1, s2, m-1, n), lcs_rec(s1, s2, m, n-1));   
}

int lcs_tab(string s1, string s2, int m, int n){
    int dp[m+1][n+1];
    
    //Initialization
    for(int i = 0; i<=m; i++)
        dp[i][0] = 0;
    for(int i = 1; i<=n; i++)
        dp[0][i] = 0;
    
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // for(int i = 0; i<=m; i++){
    //     for(int j = 0; j<=n; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout<<"Enter the strings : ";
    cin>>s1>>s2;
    int m, n;
    m = s1.size();
    n = s2.size();

    for(int i = 0; i <= m; i++)
        for(int j = 0; j<=n; j++)
            dp_rec[i][j] = -1;
    
    cout<<"Length of LCS is (Rec): "<<lcs_rec(s1, s2, m, n)<<"\n";
    cout<<"Length of LCS is (TAB): "<<lcs_tab(s1, s2, m, n);
}