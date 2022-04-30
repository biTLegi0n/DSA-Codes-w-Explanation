#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF 99999999
#define MIN -99999999
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;  
/*
    Approach : Basically, in EditDistance Problem, we have three operations and two strings, and using those three operations 
               (Insert, Delete & Replace), we have to convert string A into string B. So the major changes are in initialization and 
               in dp[i][j] = min ..... 
                - when we have an empty string, then we need to insert all the characters of another string which make us fill the dp
                  as length of currently taken string, ie dp[i][0] = i and dp[0][j] = j (all insertions)
                - After we have initialized the dp, we now have to fill the remaining table as : 
                    - if we have matching characters in the end, we will just skip those and move to next, ie fill the dp as dp[i-1][j-1]
                    - else, we choose the minimum of dp[i-1][j](insert), dp[i][j-1](delete) and dp[i-1][j-1] (replace)
*/
int main() 
{ 
  FAST;

  string s1, s2;
  cin>>s1>>s2;

  int m, n;
  m = s1.length();
  n = s2.length();

  int dp[m+1][n+1];

  for(int i = 0; i<=m; i++)
    dp[i][0] = i;
  for(int j = 1; j<=n; j++)
    dp[0][j] = j;
  
  for(int i = 1; i<=m; i++){
    for(int j = 1; j<=n; j++){
      if(s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
    }
  }
  cout<<dp[m][n]<<"\n";
} 