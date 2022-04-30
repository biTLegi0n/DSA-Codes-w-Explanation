#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vp v[100005];
/*
    Approach: In this question, we are asked to find 'k' shortest distances. To find the shortest distance in a positive weighted 
              directed graph, we use Dijkstra. So in this ques also, we use Dijkstra with some modification.
              (OBSERVATION) : In this type of question, we are given two weights to same path, ie with (a->b : 2), we can also have
                              (a->b : 5) and thus, to consider both paths to find k shortest paths, we cannot use visited array like tradi.
               - Mod 1 : We have to omit visited[] array, because in this ques, we are aksed to find k shortest paths, so that means
                         that after calculating the total weight of a 1st shortest path, we might have to visit the nodes that fall in
                         second shortest path. 
               - Mod 2 : Instead of having an array Distance[], we need to have a vector of (vector of size k each) initialized in the
                         same way we used to in traditional code. 
               - Mod 3 : After storing the distance of a node in vector<> Distance, we have to sort that particular, because we only 
                         have to update the one at (Dis[node][k-1]) k-1 because that is the worst logically. So in order to put the worst
                         or longest at last k-1, we need to sort the vector Dis[node] after each updation.    
*/

void dijkstra(int node, int k, vector <vector <int>> &Dis){
    priority_queue <pair <int, int>> q;

    Dis[node][0] = 0;
    q.push({0, node});

    while(!q.empty()){
        int a = q.top().second;
        int d = abs(q.top().first);

        q.pop();
        /*
        This below condition is important else we can face TLE. This is actually replacing the if(!visited) condition here.
        If the Dis[a][k-1] has already been optimized and is shorter than the one which is still unprocessed in queue, we can omit that
        that queue element because we already have optimised so its processing will not do any good to us :)                 */
        if(Dis[a][k-1] < d)
            continue;
        
        for(auto u : v[a]){
            int b = u.first;
            int w = u.second;

            if(Dis[b][k-1] > w + d){
                Dis[b][k-1] = w + d;
                q.push({-Dis[b][k-1], b});
                sort(Dis[b].begin(), Dis[b].end());
            }
        }
    }
}


int main()
{
    int n, m, k;
    cin>>n>>m>>k;

    for(int i = 0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        v[a].pb({b, w});
    }

    // A way to initialize a vector of vector saying that initialize it with a vector of size 'K' and filled with 'INF'
    vector <vector <int>> Dis(n+1, vector <int>(k, INF));

    dijkstra(1, k, Dis);

    for(auto u : Dis){
        cout<<"Distance graph is :-> ";
        for(auto x : u)
            cout<<x<<" ";
        cout<<"\n";
    }
}