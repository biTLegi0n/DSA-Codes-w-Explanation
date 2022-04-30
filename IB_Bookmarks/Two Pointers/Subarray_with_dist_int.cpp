#include <bits/stdc++.h>
using namespace std;
/**
   @note    In such problems, where we are asked to find number of subsets having sum <= something or having sum in a range, we
            use this concept. For example, in this question, we are asked to find number of subsets having sum in the range [0,B].
            therefore, ans = numberofsubset(B)-numberofsubset(0).
            Similiarly, if we are asked to find something in between [l,r], ans = fun(r)-fun(l).
*/
int fun(vector <int>&arr, int k){
    if(k==0) return 0;
    int low = 0, high = 0, ans = 0,dist=0;
    unordered_map <int,int> mp;
    bool flag = false;
    while(high<arr.size()){
        if(mp.find(arr[high])==mp.end()) dist++;
        if(!flag) mp[arr[high]]++;
        if(dist>k){
            mp[arr[low]]--;
            if(mp[arr[low]]==0){
                dist--;
                mp.erase(arr[low]);
            }
            low++;
            flag = true;
        }
        else
        if(dist<=k){
            flag = false;
            // subarrays ending at high
            ans += high-low+1;          // since i have to find atmost k!!!
            high++;
        }
    }
    return ans;
}
int solve(vector<int> &A, int B) {
    return fun(A,B)-fun(A,B-1);
}
