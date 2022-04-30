#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int dp[10005][10005];
/*
    Approach : This code is a Variation of MCM, where we have to do partitions on every possible position and then check which one
               best suited for us. In this ques, we need to perform minimum partitions so that the strings formed from those partit.
               are all palindromes.... So we need to break the string at various 'K' and check for minimum. We see that if we have only
               one character in our string ie l == r, then we return 0 as we cannot perform partition on one character, so is the case 
               with l>r, Thus, we have our base case as (l>=r).
                - Similiarly, we have another base case which is if the string is alrady a palindrome, then we don't perform partitions
                  In that case, we also update the dp[i][j] to 0 so that if encountered again, we directly return 0 and not call the 
                  isPalindrome function again.
                - Apart from these base cases, we only have to run the signature 'for' loop for 'k'. We put this 'k' at various posn
                  and check for minimum answer possible using recursive memoization approach. 
                    - Two variables, Left and Right are taken. They are needed to check whether if dp[i][k] or dp[k+1][j] has already
                      be found or not. if they were found before, we return them directly, saving time, else we calculate them recursively.
                      and update them in dp table
*/

// Note : We are passing 'i' and 'j' in isPalindrome function because each time, we pass a substring with different i and j. If we wouldn't
//        pass these, we would check for string 's' all the time because and not any substring of string 's'. 
bool ispalindrome(string s, int i, int j){
    // We compare the first and last characters.
    while(i<j){
        if(s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

int palin_part(string s, int i, int j){
    // #BC1
    if(i >= j)
        return 0;
    // #BC2
    if(ispalindrome(s, i, j)){
        dp[i][j] = 0;
        return 0;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = INF;
    for(int k = i; k<j; k++){
        int left, right;
    // If dp[i][k] already found, we directly return it else we find it recursively
        if(dp[i][k] != -1)
            left = dp[i][k];
        else{
            left = palin_part(s, i, k);
            dp[i][k] = left;
        }
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else{    
            right = palin_part(s, k+1, j);
            dp[k+1][j] = right;
        }
        int count = left + right + 1;
        ans = min(ans, count);
    }
    dp[i][j] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s;
    cin>>s;
    cout<<"Minimum number of partitions required to make palindromes out of it ::: "<<palin_part(s, 0, s.length()-1);
}