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
int parent[100005];
int level[100005];
/* 
This algorithm is naive approach to find the LCA. It works in O(N). its fine for me but i guess not for the ques In this approach, 
we simply calculate the difference in levels of the two nodes whose LCA is to be found. Then we keep reducing the distance of the 
lower node until the difference between their levels is zero. Once it is zero, we start reducing the levels of both the nodes, 
untill their parents are same. When their parents are found to be same, we return their parent
*/

void dfs(int node, int p){
    // This function will fill the LEVEL and PARENT array
    level[node] = 1 + level[p];
    parent[node] = p;

    for(auto u : v[node]){
        if(u!=p)            // smart way to reduce Space Complexity -_- As we dont need visited array now
            dfs(u, node);
    }
}

int main()
{
    //FAST;

    int n;
    cin>>n;
    for(int i = 1; i<=n; i++)
        parent[i] = i, level[i] = 0;

    for(int i = 1; i<n; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }   
    dfs(1, -1);

    cout<<"Enter the two nodes, A and B : ";
    int a, b;
    cin>>a>>b;
    // In order to respect our algorithm, we should always keep b's level higher then that of a's. If not, swap them 
    if(level[a] > level[b])
        swap(a, b);
    // If we don't swap them, we will have a negative diff value
    int diff = level[b] - level[a];
    while(diff > 0)
        b = parent[b], diff--;
    if(a == b)
        cout<<"Their Lowest Common Ancestor is : "<<a<<"\n";
    else{
        while(parent[a] != parent[b])
            a = parent[a], b = parent[b];
    
        cout<<"Their Lowest Common Ancestor is : "<<parent[a]<<"\n";
    }
}