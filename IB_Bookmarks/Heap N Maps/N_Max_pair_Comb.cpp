#include <bits/stdc++.h>
using namespace std;

/**
    @brief  "Nhi hua tha khud se"
            This problem is really good. Here, we have to find n pairs which have maximum sum and store them in array in
            decreasing order. So, it has a type of dijkstra approach. Here, we sort the array first, and now we start from the
            last and from there, in each iteration, we select two numbers. Now those two numbers, depend on the top of priority
            queue. We pass the sum, index i of first array, and index j of second array to the priority queue, and in each iteration
            we make a decision. we either move one pointer to the left in 1st array or in 2nd array, keeping another pointer at the
            same position. But we do this for both the arrays, ie we push i-1,j and i,j-1 to the priority queue and in each iteration
            we pass the top to the res array because it can be observed that the max sum will be one of those two pairs in each iter.

            This problem is same as Maximum Sum Combination
*/

vector<int> solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n = A.size();

    priority_queue <pair<int,pair<int,int>>> q;
    int i = A.size()-1, j = B.size()-1;
    q.push({A[i]+B[j],{i,j}});
    vector <int> res;
    map <pair<int,int>,int> mp;
    while(!q.empty() and n--){
        res.push_back(q.top().first);
        i = q.top().second.first, j = q.top().second.second;
        q.pop();
        if(mp.find({i,j-1})==mp.end())
            q.push({A[i]+B[j-1],{i,j-1}}), mp[{i,j-1}]++;
        if(mp.find({i-1,j})==mp.end())
            q.push({A[i-1]+B[j],{i-1,j}}), mp[{i-1,j}]++;
    }
    return res;
}
