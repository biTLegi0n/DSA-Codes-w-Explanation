#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF LLONG_MAX
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

ll int n, m;
ll int dis[505][505];
/*
    Approach : fLOYD Warshall is kind of brute force algorithm. We go to each node, consider it to be an intermidiate node, 
               and if it reduces the existing distance, we update the distance. We maintain three nested loops in this. 
               -> Loop 'k' : This loop is for the intermidiate nodes. Intermidiate node means that if we need to find the
                             distance between a -> b, then we consider the possibilites of all paths passing through all 
                             other node, ie, we do a -> k then k -> b, and if it reduces the overall distance[a->b], we update it
               -> Loop 'i' & 'j' : This loop is for all the nodes, ie in simpler terms, i is for rows and j is for coloums and 
                                   dis[i][j] is the minimum distance between node i and j. It considers all pairs of nodes.
*/
void floyd_warshall(){
  // For the intermidiate nodes
  for(ll int k = 1; k<=n; k++){
    // For considering all pairs of nodes.
    for(ll int i = 1; i<=n; i++){
      for(ll int j = 1; j<=n; j++){
        // If any of the node is not reachable from intermidiate 'k', we just ignore that pair
        if(dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX)
          continue;
        else
        if(dis[i][j] > dis[i][k] + dis[k][j])
          dis[i][j] = dis[i][k] + dis[k][j];
      }
    }
  } 
}
/*
    This function written below is used to detect any negative cycle, if present our graph. 
    Negative cycle is the one whose overall total weight is negative and that starts and ends at same node. 
*/
bool detect_neg_cycle(){
    for(int i = 1; i<=n; i++){
        if(dis[i][i] < 0)
            return true;
    }
    return false;
}

int main()
{
  FAST;
    ll int q;
    cin>>n>>m>>q;

    // We initialize the dis[][] matrix with INF and diagonals as 0
    for(ll int i = 1; i<=n; i++)
      for(ll int j = 1; j<=n; j++){
        if(i!=j)
        dis[i][j] = LLONG_MAX;
        else
        dis[i][j] = 0;
      }
      
    for(ll int i = 0; i<m; i++){
        ll int a, b, w;
        cin>>a>>b>>w;
        // In case, same edge has multiple weights assigned
        if(w < dis[a][b])
        dis[a][b] = dis[b][a] = w;
    }
    
    floyd_warshall();

  while(q--){
    ll int a, b;
    cin>>a>>b;
    if(abs(dis[a][b]) != INF)
    cout<<dis[a][b]<<"\n";
    else
    cout<<"-1\n";
  }
}