#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   Try to model the problem as a graph problem consider each good pair as 2-ways edges.
            Then we can divide our graph into connected component.

            Use this fact to find an solution to the problem.
 *
 */

int parent[100005];

int find(int x){
    if(parent[x] == x) return x;

    int a = find(parent[x]);
    return parent[x] = a;
}

void join(int a, int b){
    a = find(a), b = find(b);
    parent[b] = a;
}
int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    for(int i = 0; i<A.size(); i++) parent[A[i]] = A[i];

    for(auto u : C){
        join(A[u[0]-1],A[u[1]-1]);
    }

    for(int i = 0; i<A.size(); i++) parent[A[i]] = find(A[i]), parent[B[i]] = find(B[i]);

    for(int i = 0; i<A.size(); i++){
        if(A[i]!=B[i]){
            if(parent[A[i]]!=parent[B[i]]) return false;
        }
    }
    return true;
}
