#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This was one of the best problem i faced in graphs. Here, we have to visit all the nodes of a graph but not like
            normal dfs, but literally shortest path that will also include return path from a leaf. That is what makes it so
            difficult. Because, once we reach leaf, how are we supposed to record the return path as they will be visited. And
            also, if we need to find the shortest path, we need to use all the nodes as source. Thus, normal method will givr TLE.

            Thus, this new concept that i learned in this method was very helpful. Instead of using normal vector to mark visited,
            we use bitmask. How do we use it? Well, to each node, we assign a unique power of 2, which ensures that it only has one
            set bit. Now, when we move to a node, we do (that nodes bitmask | bitmask so far). This will ensure that a new and unique
            bitmask is generated. Since each one of the node is assigned a power of 2, and each one is unique. Thus, they will have
            1 bit each and taking | or two or more, will increase the set bits by one. Each time we pass a pair of node and bitmask
            and each pair is pushed in a set which will work as visited here. Now, we will note that same direction will not be
            repeated twice. I mean we wont go from 0->1 twice, because we have already handled this pair and it will be present
            in the set. This way, we can easily find the shortest path. It is simple BFS.

 */

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // There will be n bits in the bitmask if all the nodes have been traversed.
        int n = graph.size();
        // The number with n-1 set bits is (1<<i)-1;
        int req = (1<<n)-1;

        set <pair<int,int>> s;
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        for(int i = 0; i<graph.size(); i++) q.push({0,{i,1<<i}});

        while(!q.empty()){
            int len = q.top().first;
            int node = q.top().second.first;
            int code = q.top().second.second;
            q.pop();

            if(code == req) return len;
            if(s.find({node,code})!=s.end()) continue;

            s.insert({node,code});

            for(auto u : graph[node]){
                q.push({len+1,{u,(code|(1<<u))}});
            }
        }
        return 0;
    }
};