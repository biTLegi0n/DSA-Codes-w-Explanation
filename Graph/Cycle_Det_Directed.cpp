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
int color[100005];
// In order to detect cycle in a Directed Graph, we use node coloring method as checking for parent would not help us
// as we may have a two nodes directed to each other forming a cycle even when one is parent of other

// color array replaces visited array. Color = 0 (unvisited) :: Color = 1 (being visited) :: Color = 2 (visited)
bool cycle(int node){
    color[node] = 1;

    for(auto u : v[node]){
        if(color[u] == 0){
            if(cycle(u))
                return true;
        }
        else
            if(color[u] == 1)
                return true;
    }
    color[node] = 2;
    return false;
}


int main()
{
  FAST;

    int n, m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
        color[i] = 0;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
    }
    if(cycle(1))
        cout<<"This Directed Graph contains Cycle\n";
    else 
        cout<<"This Directed Graph does not have a cycle\n";
}