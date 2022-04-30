#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vp v[100005];
vi dis(100005, 0);
vi parent(100005, -1);
/*
    Approach : We were asked to write a code for Single Source Longest Path (SSSP ka bhai), thus the first thing that popped up 
               in my head was Dijkstra. As in Dijkstra, we are asked to find the shortest paths, we can modify it a bit to get the longest
               path.
               -> If we replace all the edges with negative edges and then find the shortes path, that will eventually give us the longest path
                  because -5 < -3 but abs(-5) > abs(-3). Thus, Dijk() would return us -5 but taking its abs() would give us 5 (ie Longest)
               -> But it arises a question in our mind that Dijkstra should not work with negative weights, but acutually, its not so
                  Dijkstra do not work with negative edges if it also have some positive edges with it. For eg, if we have 
                  1->2(500), 2->3(-100), 1->3(450), in this eg, as Dijkstra is a Greedy algo, thus it would directly choose 1->3(450)
                  and discard [1->2(500)&2->3(-100) => 400] case, because it sees the shorter edge and proceeds with it.
                  Dijkstra is based on monotonicity, ie. all the edges are increasing in weights. It says that the weight always increases
                  ie, according to Dijk, in previous eg, if we choose 500, then on next iteration, the weight will only be 500 + (x), where
                  x is always +ve. Based on this fact, we use it in case of all positives and no negative cycles.
               -> So in this question, we make all the edges as -1, making it monotonious in nature  (negative monotonic). There could be a 
                  issue if there are negative cycles, but we have a DAG. 
        Cond of Dijk : Dijkstra works when distance/cost is monotonic, ie all positives or negative and there must not be any negative cycles. 

*/
void dijkstra(int node){

    priority_queue <pair <int, int>> q;
    q.push({0, node});
    dis[node] = 0;

    while(!q.empty()){
        int a = q.top().second;
        int d = q.top().first;
        q.pop();

        if(dis[a] < d)
            continue;

        for(auto u : v[a]){
            int b = u.first;
            int w = u.second;

            if(dis[b] > dis[a] + w)
                dis[b] = dis[a] + w, parent[b] = a;
            q.push({-dis[b], b});
        }
    }
}

int main()
{

    int n, m;
    cin>>n>>m;
    
    parent.resize(n+1);
    dis.resize(n+1);

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb({b, -1});
    }

    dijkstra(1);
    int max_node, max_dis = 0;
    for(int i = 1; i<=n; i++){
        if(abs(dis[i]) > max_dis)
            max_dis = abs(dis[i]), max_node = i;
    }
    if(max_dis == 0)
        cout<<"1 is not connected to any node :(\n";
    else{
        int y = max_node;
        vi path;
        while(parent[y] != -1){
            path.pb(y);
            y = parent[y];
        }
        path.pb(1);
        reverse(path.begin(), path.end());
        cout<<"Maximum Distance is : "<<max_dis<<" to the node : "<<max_node<<"\nThe path is : ";
        for(auto u : path)
            cout<<u<<" ";
        cout<<"\n";
    }
}