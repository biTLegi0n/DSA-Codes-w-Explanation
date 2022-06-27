#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This problem is just 3 sum in a loop. What we did in 3 sum, is what we will do here. We loop the array, fix a number, change the
            target to target-(current element), and now, look for such three numbers that sum up to target-current. 
            The overall complexity of this approach will be O(n^3). And space complextiy of this problem is O(N).
            It could be done in O(1), if we use two pointers approach after sorting the array, coz we dont need to maintain any sort of order

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