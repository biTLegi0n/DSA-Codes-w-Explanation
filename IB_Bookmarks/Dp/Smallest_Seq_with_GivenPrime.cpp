#include <bits/stdc++.h>
using namespace std;
/*
    naive approach used min heap data structure to find first k elements a better approach is using dp, this problem is
    exactly same as ugly nnumbers

    vector<int> Solution::solve(int a, int b, int c, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        vector<int> ans;
        map<int, int> mp;
        while(ans.size() < k){
            int mn = pq.top();
            pq.pop();
            if(mp.find(mn) != mp.end())
                continue;

            mp[mn]++;
            ans.push_back(mn);
            pq.push(mn * a);
            pq.push(mn * b);
            pq.push(mn * c);
        }
        return ans;
    }
*/
/**
 * In the below code, it can be seen that we take the minimum out of all A,B,C and put it in the dp array and update their value
 * Note that we are multiplying dp[i,j,k] with a,b,c and not minimum. Also we do not take 'else' to avoid duplicacy
*/
vector<int> solve(int a, int b, int c, int n){
    int i = 0, j = 0, k = 0;

    vector<int> dp(n + 1);
    dp[0] = 1;
    int A = a, B = b, C = c;
    for(int idx = 1; idx <= n; idx++){
        int mn = min(A, min(B, C));
        dp[idx] = mn;

        if(mn == A){
            i++;
            A = dp[i] * a;
        }
        if(mn == B){
            j++;
            B = dp[j] * b;
        }
        if(mn == C){
            k++;
            C = dp[k] * c;
        }
    }

    dp.erase(dp.begin());

    return dp;
}