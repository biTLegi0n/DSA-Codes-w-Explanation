#include <bits/stdc++.h>
using namespace std;

/**
   @brief

 */

vector <vector <int>> threesum(vector <int>&arr, int b, int idx){
    vector <vector <int>> res;
    for(int i = idx+1; i<arr.size(); i++){
        if(i==idx) continue;
        unordered_map <int,int> mp;
        int sum = b-arr[i];
        for(int j = i+1; j<arr.size(); j++){
            if(j==idx or j==i) continue;
            if(mp.find(sum-arr[j])!=mp.end())
                res.push_back({arr[i],arr[j],arr[mp[sum-arr[j]]]});
            mp[arr[j]] = j;
        }
    }
    return res;
}
vector<vector<int>> fourSum(vector<int> &A, int B) {
    vector <vector <int>> res;

    // Ye check karna important h else TLE aajati h
    if(A.empty()) return res;

    set <vector <int>> s;
    for(int i = 0; i<A.size(); i++){
        vector <vector <int>> temp = threesum(A,B-A[i],i);
        for(auto u : temp){
            u.push_back(A[i]);
            sort(u.begin(),u.end());
            s.insert(u);
        }
    }
    for(auto u : s) res.push_back(u);
    return res;
}