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
    Approach : This ques is just as same as Finding LCS. The only difference in this is that we dont add 1 to dp[i-1][j-1] if the two
               matching characters are at same indices. Thats because they cannot be considered as repeating subsequence (we are checking
               in the same string, just copied it in another and then searching for LCS where indices of characters dont match)

    Input: str = "abc"
    Output: 0
    There is no repeating subsequence

    Input: str = "aab"
    Output: 1
    The two subssequence are 'a'(first) and 'a'(second). 
    Note that 'b' cannot be considered as part of subsequence 
    as it would be at same index in both.

    Input: str = "aabb"
    Output: 2

    Input: str = "axxxy"
    Output: 2
*/
int longest_rep_subseq(string str){
    int m = str.length();
		    
	int dp[m+1][m+1];
		    
    for(int i = 0; i<=m; i++)
	    dp[i][0] = 0, dp[0][i] = 0;
		       
	for(int i = 1; i<=m; i++){
        for(int j = 1; j<=m; j++){
            // i!=j is the only change in this whole code. This way, we find the length of Longest Repeating SubSeq.
	        if(str[i-1] == str[j-1] && i!=j)
	            dp[i][j] = 1 + dp[i-1][j-1];
	        else
	            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // for(int i = 0; i<=m; i++){
    //     for(int j = 0; j<=m; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }

    return dp[m][m];
}

int main()
{
    string s;
    cin>>s;
    cout<<"Length of Longest Repeating Subsequence is : "<<longest_rep_subseq(s)<<"\n";
}