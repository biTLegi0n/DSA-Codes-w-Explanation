#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF 99999999
#define MIN -99999999
#define pb push_back
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vi v[100005];
int visited[100005];
int d[100005];

// The approach is simple. We are calling DFS 2 times, One DFS will take us to any last leaf node
// From this node, we will call another DFS which will give us the diameter of the tree
void dfs(int node){
    visited[node] = 1;
    
    for(auto u : v[node])
    if(!visited[u])
    d[u] = d[node] + 1, dfs(u);
    // It is important to NOTE that d[u] = ..... is written before DFS call on Child
    // That is because If we call DFS before d[u] call, Then all the d[] values will remain 0
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;

    for(int i= 1; i<=n; i++)
    visited[i] = 0, d[i] = 0;

    for(int i = 1; i<=m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    d[1] = 0;
    dfs(1);
    int max_node, max_d = 0;
    for(int i = 1; i<=n; i++){
        if(d[i]>max_d)
        max_d = d[i], max_node = i;
    }
    for(int i = 1;i <=n; i++)
    visited[i] = 0, d[i] = 0;
    
    dfs(max_node);

    int ans = 0;
    for(int i = 1; i<=n; i++)
    if(d[i] > ans)
    ans = d[i];
    cout<<"Diameter/ Longest path in Tree is : "<<ans<<"\n"; 
}