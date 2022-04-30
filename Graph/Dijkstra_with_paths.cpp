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

vp v[100005];
int visited[100005];
int d[100005], parent[100005];
/**
 * @brief We dont actually need visited array in dijkstra. wE can replace the use of visited with the condition
 *                                  if(d>d[a]) continue;
 *
 * @param node
 */
void dijkstra(int node){

    priority_queue <pair <int, int > > q;
    q.push(mp(0, node));
    d[node] = 0;

    while(!q.empty()){
        int a = q.top().second;
        q.pop();

        if(!visited[a]){
            visited[a] = 1;

            for(auto u : v[a]){
                int b = u.first;
                int w = u.second;

                if(d[a] + w < d[b])
                d[b] = d[a] + w, parent[b] = a;
                q.push(mp(-d[b], b));
            }
        }

    }
}

int main()
{
  //FAST;

    int n, m;
    cin>>n>>m;

    for(int i = 0; i<n; i++)
    d[i] =  INF, parent[i] = i, visited[i] = 0;
    parent[1] = -1;

    for(int i = 0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        v[a].pb(mp(b, w));
        v[b].pb(mp(a, w));
    }

    dijkstra(0);

    for(int i = 0; i<n; i++)
    cout<<"Distance of node "<<i<<" from 0 is: "<<d[i]<<"\n";
    int dest;
    cin>>dest;
    vi par;

    while(parent[dest] != -1){
        par.pb(dest);
        dest = parent[dest];
    }
    par.pb(0);

    reverse(par.begin(), par.end());

    for(auto u : par)
    cout<<u<<" ";
}