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

vector <pair <ll, ll>> v[100005];
vector <ll> dis;
/*
    Approach : iN this question, we are given multiple different weights to same edges and are asked to find the shortest distance
               to every node. It is same as that of Parent Dijkstra except a few differences. 
                1. We dont maintain an visited array in these questions, because maintaing that will bound us and we would only 
                   visit a node once. But, since different weights are given on same edge, we might need to consider same edge 
                   again and again, so instead of using that, we put another condition, 
                        if(dis[a] < d) :: This condition replaces the statement if(!visited[a]) of parent dijkstra and if that
                    particular distance has been optimised already, and the one waiting in the queue has larger distance than the
                    optimised one, we will simply ommit the case. If still facing any doubts, try using pen paper.
                2. (Actually this is not any difference. I am writing this so as to be sure) We will push the updated distance in 
                    the queue only if it is updated. ie in the if() statement's body only. Failing to do so can cause us an infinite
                    loop, because the distance, updated or not, will keep on pushing in the queue endlessly, if the graph has any cycle. 
*/
void dijkstra( ll int node){

    priority_queue <pair <ll int, ll int>> q;
    dis[node] = 0;
    q.push({0, node});

    while(!q.empty()){
        ll int a = q.top().second;
        ll int d = abs(q.top().first);
        q.pop();
        
        // Replaces the if(!visited[a]) statement
        if(dis[a] < d)
            continue;
        
        for(auto u : v[a]){
            ll int b = u.first;
            ll int w = u.second;

            if(dis[b] > dis[a] + w){
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}

int main()
{
  FAST;
	ll int n, m;
    cin>>n>>m;
    dis.resize(n+1);

    fill(dis.begin(), dis.end(), INF);

    for(ll int i = 1; i<=m; i++){
        ll int a, b, w;
        cin>>a>>b>>w;
        v[a].pb({b, w});
    }

    dijkstra(1);
    for(ll int i = 1; i<=n; i++)
        cout<<dis[i]<<" ";
    cout<<"\n";
}