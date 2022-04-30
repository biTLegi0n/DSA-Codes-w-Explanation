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

int bfs(int source, int dest){
    visited[source] = 1;
    
    queue <int> q;
    q.push(source);

    while(!q.empty()){
        int a = q.front();
        if(a == dest)
            return d[a];
        q.pop();
        for(auto u : v[a]){
            if(!visited[u]){
                visited[u] = 1;
                d[u] = d[a] + 1;
                q.push(u);
            }
        }   
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int q;
    cin>>q;
    while(q--){
        for(int i = 1; i<=n; i++)
            visited[i] = 0, d[i] = 0;
        
        int source, dest;
        cin>>source>>dest;
        cout<<bfs(source, dest)<<"\n";
    }
}
