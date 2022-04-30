#include <bits/stdc++.h>
using namespace std;

/**
   @brief   In this problem, with my intuition, they were throwing TLE. Thus i went with a discussion solution. Well,
            they did this problem using MCM concept where they run a for loop in remaining string and call the function from
            every index. Basically, we start loop from first index, keeping the count of Ws and Bs and then at each index,
            we call the function. Then, while checking for minimum answer, we add the cost of current function call, ie w*b
            This way, if at any moment, we are not able to find any value, we return INT_MAX. This question, on first sight
            gives hints to use MCM. It was stupidity not to use it at first.

 */

int dp[1002][1002];
int fun(int idx, string str, int k){
    if(idx>=str.size()) return 0;
    if(k<=0) return INT_MAX;

    if(dp[idx][k]!=-1) return dp[idx][k];

    int w = 0,b=0,ans = INT_MAX;
    for(int i = idx; i<str.size(); i++){
        if(str[i]=='W') w++;
        else b++;

        int count = fun(i+1,str,k-1);
        if(count!=INT_MAX)
            ans = min(ans,w*b+count);
    }
    return dp[idx][k] = ans;
}
int arrange(string str, int k) {
    if(k>str.size()) return -1;
    memset(dp,-1,sizeof(dp));
    int ans = fun(0,str,k);
    if(ans == INT_MAX) return -1;
    return ans;
}
