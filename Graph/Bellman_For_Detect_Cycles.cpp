#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF 1e16
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vector <pair <ll, ll>> v[100005];
ll dis[100005];
ll n, m;
bool cycle_exist = false;

/*
    Approach : Bellman Ford algorithm says that after performing (n-1) relaxations, ie reducing distance. We will create an array
               of distances d[0…n−1], which after execution of the algorithm will contain the answer to the problem. In the beginning
               we fill it as follows: d[v]=0, and all other elements d[] equal to infinity ∞
                    The algorithm consists of n-1 phases. Each phase scans through all edges of the graph, and the algorithm tries
               to produce relaxation along each edge (a,b) having weight c. Relaxation along the edges is an attempt to improve the
               value d[b] using value d[a]+c. In fact, it means that we are trying to improve the answer for this vertex using edge (a,b)
               and current response for vertex a. It is claimed that n−1 phases of the algorithm are sufficient to correctly calculate
               the lengths of all shortest paths in the graph, however, even after n-1 relaxations we are seeing changes in dist[]
               upon doing relaxations, then that means we have a negative cycle(again, we believe that the cycles of negative weight do not exist).
               For unreachable vertices the distance d[] will remain equal to infinity ∞
*/

void bellman_ford(ll int source){
    // This bool variable somewhat improves the complexity of program in few cases, by telling us whether or not any dis[] changed in last itr.
    bool changed = false;
    for(ll int i = 1; i<n; i++){
        for(ll int a = 1; a<=n; a++){
            if(dis[a] != INF)
                for(auto u : v[a]){
                    ll int b = u.first;
                    ll int w = u.second;
                    if(dis[b] > dis[a] + w){
                        dis[b] = dis[a] + w;
                        changed = true;
                    }
                }
            }
        if(!changed) break;
    }
    // We set all the nodes that lies in cycle, to -INF. So if our node has dis[] = -INF, then that lies in a neg cycle.
    if(changed){
        for(ll int i = 1; i<n; i++){
            for(ll int a = 1; a<=n; a++){
                if(dis[a] != INF){
                    for(auto u : v[a]){
                        ll int b = u.first;
                        ll int w = u.second;
                        if(dis[b] > dis[a] + w){
                            dis[b] = -1*INF;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    //FAST;
    cin>>n>>m;

    for(ll int i = 1; i<=n; i++)
        dis[i] = INF;
    dis[1] = 0;

    // Graph is Directed
    for(ll int i = 0; i<m; i++){
        ll int a, b, w;
        cin>>a>>b>>w;
        v[a].pb({b, w});
    }
    bellman_ford(1);

    cout<<"The distance array is : ";
    for(int i = 1; i<=n; i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
    if(dis[n] == -1*INF || dis[1] == -1*INF)
        cout<<"-1\n";
    else
        cout<<dis[n]<<"\n";
}