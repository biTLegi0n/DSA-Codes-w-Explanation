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
int inTime[100005];
int low[100005];
int timer;

// This is similiar to Bridges 
// The only major diff is that In cases of articulation points, We have to deal with the root node
// That is because it is considered to be an cut vertex in most cases but it is not
// If root node has more than one children then it is a cut vertex else not
// https://cp-algorithms.com/graph/cutpoints.html#toc-tgt-1
void bridges(int node, int parent){
    visited[node] = 1;
    inTime[node] = low[node] = timer;
    timer++;
    int child = 0;

    for(auto u : v[node]){
        if(u == parent)
        continue;

        if(visited[u])
            low[node] = min(low[node], inTime[u]);          // We compare with inTime in case of back edge 
        else{
            bridges(u, node);

            if(low[u] >= inTime[node] && parent != -1)       // Don't get confused here, This condition is checked while backtracking
                cout<<node<<" is an articulation point\n";      // If we take the casual ex, then u is 1 and node is 0

            low[node] = min(low[node], low[u]);             // We compare with low time in case of backtracking
            child++; 
        }
    }
        if(child > 1 && parent == -1)
        cout<<node<<" which is root is an articulation point\n";
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++)
    visited[i] = 0, inTime[i] = 0, low[i] = 0;

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    bridges(1, -1);

}