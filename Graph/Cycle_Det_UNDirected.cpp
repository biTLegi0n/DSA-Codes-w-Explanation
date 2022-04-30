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

// We are applying simple concept of back edge which is if any node is pre visited but its not the 
// parent of the current node, then it is the node in continuation, and hence we encountered a back edge
bool cycle_det(int node, int parent){
    visited[node] = 1;

    for(auto u : v[node]){
        if(!visited[u]){
            if(cycle_det(u, node))
                return true;
            }
        else
            if(u != parent)
                return true;
    }
    return false;
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    if(cycle_det(1, -1))
        cout<<"Following graph contains cycle\n";
    else    
        cout<<"Following graph does not contain any cycle\n";
}