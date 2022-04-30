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
int size[100005];

// In this problem, DFS function will return us the size of every subtree
int dfs(int node){
    visited[node] = 1;
    int sub_size = 1;       // Counting the root node as well

    for(auto u : v[node]){
        if(!visited[u])
            sub_size += dfs(u);         // as this DFS call will return us the size of subtree rooted at u
    }
    size[node] = sub_size;              // The answer from that DFS call will be added in this sub_size var
    return sub_size;
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++)
    visited[i] = 0;

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(1);

    for(int i = 1; i<=n; i++)
        cout<<"Size of subtree rooted at "<<i<<" is : "<<size[i]<<"\n";
}