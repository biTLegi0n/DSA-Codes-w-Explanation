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
/*
        ============================ THEORY FOR KRUSKAL'S MINIMUM SPANNING TREE ALGO ============================
Kruskal's algorithm to find minimum spanning tree uses Disjoint Sets. It says that we first sort all the edges according to 
their weights and then one by one start joining/merging them. We should avoid joining two nodes if there already exists a path
between them. Below is the implementation of kruskal's algorithm.
*/
vector <pair <int, pair <int, int>> > v;
int parent[100005];

// We have used path compression. Not necessary but just for sake of Time Complex.
int find(int a){
    if(parent[a] == a)
        return a;
        
    // We can also do : return(parent[a]);
    int x = find(parent[a]);
    parent[a] = x;
    return x;
}

void join(int a, int b){
// We directly did this because we have already put the condition sof same parents down there in main function
// If we didn't do it there, then we would have put a condition in here and wrote accordingly
        parent[b] = parent[a];          
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;

    for(int i = 0; i<n; i++)
    parent[i] = i;

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        v.pb({w, mp(a,b)});
    }

    sort(v.begin(), v.end());               // Sorting in pairs is done according to first element
    cout<<"\nEdges after sorting : \n";
    for(auto u : v){
        cout<<u.second.first<<"-->"<<u.second.second<<"   Weight :  "<<u.first<<"\n";
    }
    int sum = 0;
    for(int i = 0; i<m; i++){                   // i<m because we need to track down edges. We could also take v.size();
        int a, b, w;
        a = find(v[i].second.first);            // Either make 'a' and 'b' equal to parents now or later you have to 
        b = find(v[i].second.second);           // compare them everytime
        w = v[i].first;

        if(a == b)              // We can also do find(a) == find(b)
        continue;
        else{
            join(a, b);         // if we didn't do make a and b equal to their Godfathers, 
            sum += w;           // then we had to do : join(find(a), find(b)) or we should have modified our Join() f unction
        }
    }
    cout<<"Total MST sum is : "<<sum<<"\n";
}