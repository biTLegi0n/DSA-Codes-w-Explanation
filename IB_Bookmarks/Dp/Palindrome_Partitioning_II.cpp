#include <bits/stdc++.h>
using namespace std;

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

int dp[505][505];
bool ispalin(int l, int r,string str){
    while(l<=r){
        if(str[l]!=str[r]) return false;
        l++, r--;
    }
    return true;
}

int fun(int l, int r, string str){
    if(l>=r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];
    if(ispalin(l,r,str)) return dp[l][r] = 0;

    int ans = INT_MAX;
    for(int i = l; i<r; i++){
        int left = INT_MAX, right = INT_MAX;
        if(dp[l][i]!=-1) left = dp[l][i];
        else left = fun(l,i,str);
        if(dp[i+1][r]!=-1) right = dp[i+1][r];
        else right = fun(i+1,r,str);

        ans = min(ans,left+right+1);
    }
    return dp[l][r] = ans;
}

int minCut(string A) {
    memset(dp,-1,sizeof(dp));
    return fun(0,A.size()-1,A);
}
