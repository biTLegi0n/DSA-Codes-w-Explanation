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
vector < vector <int> > paths;
vi path;

// We are using simple DFS approach. Time Complexity of this method is exponential for sure, but this is the way to do this.
// We have to unvisit the current node after its testing is done for a cycle starting from a fixed node, as it may be a 
// part of another cycle i.e cycle starting from another node. #backtracking
void dfs(int source, int dest){
    path.pb(source);
    visited[source] = 1;
    
    if(source == dest)
        paths.pb(path);
    else{
        for(auto u : v[source]){
            if(!visited[u])
                dfs(u, dest);
        }
    }
    // # BackTrack 
    path.pop_back();
    visited[source] = 0;
}

int main()
{
    int n, m;
    cin>>n>>m;
    
    for(int i = 0; i<n; i++)
        visited[i] = 0;

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
    }
    system("Color 0C");
    cout<<"Color turned RED due to system('color 0c') commnad\n";
    
    cout<<"Enter the source and destination: ";
    int source, dest;
    cin>>source>>dest;
    dfs(source, dest);
    cout<<"All possible paths areL: \n";
    for(auto u : paths){
        for(auto u1 : u)
            cout<<u1<<" ";
        cout<<"\n";
    }
}