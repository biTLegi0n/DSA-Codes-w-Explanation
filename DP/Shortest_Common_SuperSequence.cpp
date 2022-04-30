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
    Approach: To Print or find the SCS, we have two methods; 
                    1 : In which we make the dp table according to SCS direct
                    2 : In which we find SCS by finding LCS
                Differences : There is a single change in these two. That is in case of making dp table accn to SCS, we write
                              dp[i][j] = MIN(dp[i-1][j], dp[i][j-1]) instead of MAX and while printing, we move to the min block.
                    That's so because, in case of supersequence, we are finding a string which contains both strings and which is 
                    SHORTEST unlike LCS which is LONGEST.
                    Also there are minor changes in printing IF conditions (They change according to MIN and MAX).
                The only difference in this code and printing LCS code is that, we push the characters even if they are mismatched
                i.e if we shift above, we push str[x-1] and if we shift left, we push str[y-1]. This way, we get SuperrSeq.
*/
void LCS(string s1, string s2){
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

    string res = "";
    int x = m, y = n;
    while(x > 0 && y > 0){
         // Characters are same, thus x--, y-- (diagonally up)
        if(s1[x-1] == s2[y-1]){
            res.pb(s1[x-1]);
            x--, y--;
        }
        else{
        // Characters mismatched :: move to the block having max value and push the character corresponding to x string s1
            if(dp[x-1][y] > dp[x][y-1])
                res.pb(s1[x-1]), x--;
            else
        // Characters mismatched again. This time we push the characters corresponding to y in string s2
                res.pb(s2[y-1]) ,y--;
        }
    }
    // We break free from the above loop if any one of x or y = 0. Thus these two loops ensures to push all the remaining characters
    while(x > 0){
        res.pb(s1[x-1]);
        x--;
    }
    while(y > 0){
        res.pb(s2[y-1]);
        y--;
    }
    // If we are only asked length, we can do so by doing s1.length + s2.length - lcs.length
    reverse(res.begin(), res.end());
    // Reversing the resulting string is important so as to maintain the order
    cout<<"SCS is : "<<res<<"\n";
}

int main()
{
    string s1, s2;
    cout<<"Enter the two strings : ";
    cin>>s1>>s2;
    LCS(s1, s2);
}