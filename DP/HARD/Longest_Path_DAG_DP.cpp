#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vi v[100005];
int visited[100005];
int dp[100005];
/*
    Approach : iFF only we are asked to find the longest distance and not to print the path, we can use this algorithm. I've tried 
               but i found no way to print that path. This is simple 1D dP problem where (if the distance of any child + 1) > dis[node]
               then we update it. We need to have a visited array in this in order to avoid repetitive calls of any particular node.
               The graph should be Directed and must not have any cycles
               -> The TC of this code is O(N) Better than O(M+N). 
*/
void dfs(int node){
    visited[node] = 1;

    for(auto u : v[node]){
        if(!visited[u])
            dfs(u);
        dp[node] = max(dp[node], 1 + dp[u]);        // Max -> to find the longest distance
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
        visited[i] = 0, dp[i] = 0;
    
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
    }

    for(int i = 1; i<=n; i++){
        if(!visited[i])
            dfs(i);
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(dp[i] > ans)
            ans = dp[i];
    }
    cout<<"The max Length in DAG is : "<<ans<<"\n";
}