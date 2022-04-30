/**
 * @file Finding_K_closest_Numbers.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * Problem Link : https://leetcode.com/problems/find-k-closest-elements/
 * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

    An integer a is closer to x than an integer b if:

        |a - x| < |b - x|, or
        |a - x| == |b - x| and a < b

    

    Example 1:

    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]

    Example 2:

    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4]

 */

/**
 * 
 * -> used MIN_HEAP to find the closest ones. Complexity of this algorithm is O(klogn)
 */

#include <bits/stdc++.h>
using namespace std;

vector <int> find_k_elem(vector <int> &arr, int k, int x){
    priority_queue <pair <int, int>> q;
    vector <int> res;
    
    for(int i = 0; i<arr.size(); i++){
        q.push({abs(x-arr[i]), arr[i]});
    }
    while(q.size()>k){
        int a = q.top().second;
        q.pop();
    }
    while(!q.empty()){
        int n = q.top().second;
        res.push_back(n);
        q.pop();
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    int k, x;

    cin>>k>>x;
    vector <int> res = find_k_elem(arr, k, x);
    for(auto u : res)
        cout<<u<<" ";
    cout<<"\n";
}