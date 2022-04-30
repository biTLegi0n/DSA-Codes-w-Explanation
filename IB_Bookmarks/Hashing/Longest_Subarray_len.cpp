#include <bits/stdc++.h>
using namespace std;

/**
  @brief    At first, i misread the problem. it asked me to find the length of longest subarray with ones one greater than 0s.
            To do such problems, consider 0 and -1 and 1 and 1 and count the sum and do just like the rest.

 */

int solve(vector<int> &A) {
    unordered_map <int,int> mp;
    // basically, i replaced every 0 with -1 and checked for sum = 1
    int sum = 0, ans = 0;
    for(int i = 0; i<A.size(); i++){
        if(A[i]==0) sum--;
        else sum++;
        if(sum==1) ans = i+1;
        else{
            if(mp.find(sum-1)!=mp.end()) ans = max(ans,i-mp[sum-1]);
        }
        if(mp.find(sum)==mp.end())
            mp[sum] = i;
    }
    return ans;
}