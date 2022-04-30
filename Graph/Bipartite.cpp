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
int color[100005];      // Color array to hold color of each node
// Bipartite graph is a graph in which it is possible to color all its nodes such that no two adjacent nodes are coloured same.

bool bipartite(int node, int c){
    visited[node] = 1;
    color[node] = c;
    
    for(auto u : v[node]){
        if(!visited[u]){
            if(!bipartite(u, c^1))
                return false;
            }
        else
            if(color[u] == color[node])
                return false;
    }
    return true;
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
    visited[i] = 0, color[i] = 0;

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    if(bipartite(1, 0))
    cout<<"This graph is bipartite graph\n";
    else
    cout<<"This graph is not bipartite\n";
}