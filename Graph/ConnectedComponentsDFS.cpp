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

void dfs(int node){
    visited[node] = 1;

    for(auto u : v[node])
        if(!visited[u])
            dfs(u);
}

int main()
{
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
  
  int cc_count = 0;
  for(int i = 1; i<=n; i++)
  if(!visited[i])
  dfs(i), cc_count++;

  cout<<"Total number of connected components are : "<<cc_count<<"\n";

}