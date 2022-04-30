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
    Approach: We follow up the basis of LCS (Length Finding code). We start from the last block ie dp[m][n]. From there
              we move up in following way :
                - If we find the last characters are same, we redo what we did to fill the matrix i.e we do i--, j--
                  and since the characters are same, thus this has to be a part of LCS. So we add this in our res string
                - If Characters are mismatching, we move to the block having maximum value among dp[i-1][j] & dp[i][j-1]
                  because that's what we did to fill the matrix.
            So basically, we are following the path we took to fill the matrix and just adding the same characters in our res string
*/
void Print_lcs(string s1, string s2){
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++)
        dp[i][0] = 0;
    for(int j = 1; j<=n; j++)
        dp[0][j] = 0;

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<"Length of LCS is: "<<dp[m][n]<<"\n";

    string res = "";
    int x = m, y = n;
    while(x > 0 && y > 0){
        // Characters are same, thus x--, y-- (diagonally up)
        if(s1[x-1] == s2[y-1]){
            res.pb(s1[x-1]);
            x--, y--;
        }
        else{
        // Characters mismatched :: move to the block having max value :)
            if(dp[x-1][y] > dp[x][y-1])
                x--;
            else
                y--;
        }
    }
    reverse(res.begin(), res.end());
    cout<<"Longest Common Subsequence is : "<< res<<"\n";
}

int main()
{
    string s1, s2;
    cout<<"Enter the two strings : ";
    cin>>s1>>s2;
    Print_lcs(s1, s2);
}