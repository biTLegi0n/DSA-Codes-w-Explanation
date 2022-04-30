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
    Approach : One might wonder that why we needed DP in this ques while we didn't in https://leetcode.com/problems/longest-continuous-increasing-subsequence/
               Well, in that ques, we had to find LongestIncreasing thus that could directly be solved without dp as we just had to 
               check its increasing nature and break whenever we find any number smaller than its previous
               BUT, in this ques, we have to find a common substring which could be present anywhere in the string. For ex :
                - In ABCDGHR AND BACDGRH, the common substr is CDG, which is present in the mid of both arrays thus we have to 
                  consider every small case and thus we need DP, ie to compare every character. :) 
*/

int LCS(string s1, string s2){
    int m = s1.size();
    int n = s2.size();

    int dp[m+1][n+1];

    for(int i = 0; i<=m; i++)
        dp[i][0] = 0;
    for(int j = 1; j<=n; j++)
        dp[0][j] = 0;
    
    int ans = 0;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                // If we find two characters matching, we add 1 and update the ans value accordingly
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > ans)
                    ans = dp[i][j];
            }
            else
            // If in the going sequence, we find any two mismatching characters, we reset the value to 0 
            dp[i][j] = 0;
        }
    }
    return ans;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<"Length of Longest Common Substring : "<<LCS(s1, s2);
}