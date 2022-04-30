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
    Approach : This question on first sight, might not be seen as a direct implementation of LCS but it is. In input we are given 
               only one string but we are asked the longest palindromic subsequence, which is same when read fwd or bwd. Thus 
               that sounds like a LCS in a string and its reverse. For ex : S1 = AGBCBA has a Palindromic SubSeq : ABCBA 
                    - We can observe that AGBCBA & ABCBGA has LPS ABCBA. Thus we can conclude by saying that LPS is a direct 
                      implementation of LCS and that a LPS is a LCS between a string and its reverse. ;)
                    - Also note one another type of problem formed from this ques, If we are asked to find the minimum number of 
                      deletions to make a string palindrome, then we just find the length of longest palindrome and subtract it from
                      the length of original string. That would give us the Minimum number of deletions required to make string palin.
*/

int LPS(string s1){
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    int n = s2.size();

    int dp[n+1][n+1];

    for(int i = 0; i<=n; i++)
        dp[i][0] = 0;
    for(int j = 1; j<=n; j++)
        dp[0][j] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // for(int i = 0; i<=n; i++){
    //     for(int j = 0; j<=n; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    return dp[n][n];
}

int main()
{
    string s1;
    cin>>s1;
    cout<<"Length of Longest Palindromic SubSeq is : "<<LPS(s1);
}