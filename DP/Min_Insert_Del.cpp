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
    Approach : We can observe the fact that to convert a string into another using only insertion and Deletion, we need to modify
               the characters which are not in LCS. ie in HEAP & PEA, we need to modify HP & P. Thus EA remains where it is
               So we can say that total operations of insertion and deletion will be on HP & P. which makes the count = 3;
               We delete HP (count = 2) and insert P in their place (count = 3)
               Thats what we did in the code. We find the length of LCS, then we subtract it from both the string's lengths
               Which leaves us with the characters we need to modify. We then add those two lengths and return.
*/

int minOperations(string str1, string str2) 
{ 
    int m = str1.size();
    int n = str2.size();
	    
    int dp[m+1][n+1];
	    
    for(int i = 0; i<=m; i++)
	    dp[i][0] = 0;
    for(int j = 1; j<=n; j++)
	    dp[0][j] = 0;
	   
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(str1[i-1] == str2[j-1])
	            dp[i][j] = 1 + dp[i-1][j-1];
            else
	            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
	}
    //Could be done on any string :)
	int insert = str2.size() - dp[m][n];
    int del = str1.size() - dp[m][n];
	    
	return insert + del;
} 

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<minOperations(s1, s2);
}