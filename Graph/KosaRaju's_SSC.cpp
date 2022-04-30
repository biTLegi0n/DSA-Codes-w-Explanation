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
vi tp[100005];
int visited[100005];
vi order;          // This is the Order vec which is generated from 1st DFS call and which helps in 2nd DFS call
vi SSC;            // This is the vector that holds a single source Connected Component

/*
If we sort all vertices v∈V by decreasing of their exit moment tout[v] then the first vertex u is going to be a vertex from "root" 
strongly connected component, i.e. a vertex that no edges in a condensation graph come into. Now we want to run such search from 
this vertex u so that it will visit all vertices in this strongly connected component, but not others; doing so, we can gradually
select all strongly connected components: let's remove all vertices corresponding to the first selected component, and then let's find
a vertex with the largest value of tout, and run this search from it, and so on.

    Let's consider transposed graph GT, i.e. graph received from G by reversing the direction of each edge. Obviously, this graph will have the
same strongly connected components as the initial graph. Moreover, the condensation graph GSCC will also get transposed. It means that there
will be no edges from our "root" component to other components.
*/

void dfs(int node){
    visited[node] = 1;

    for(auto u : v[node])
        if(!visited[u])
            dfs(u);

    order.pb(node);
}

void dfs2(int node){
    visited[node] = 1;
    
    for(auto u : tp[node])
        if(!visited[u])
            dfs2(u);

    SSC.pb(node);
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
        visited[i] = 0, SSC.clear(), order.clear();

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        tp[b].pb(a);
    }

    for(int i = 1; i<=n; i++)
        if(!visited[i])
        dfs(i);

    for(int i = 1; i<=n; i++)
        visited[i] = 0;
    
    for(int i = 1; i<=n; i++){
        // The reason why we are checking it from last element of order is precisly why we say "Order is in increasing order"
        // The last element of order corresponds to that node of condensation graph whose outdegree is 0. Thus dfs call would only visit component.
        if(!visited[order[n-i]]){
            SSC.clear();
            dfs2(order[n-i]);
        
            cout<<"Strongly Connected Component: \t";
            for(auto p : SSC)
                cout<<p<<" ";
            cout<<"\n";
        }
    }
}