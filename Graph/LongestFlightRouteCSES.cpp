/*
Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. 
Of course, Uolevi wants to choose a trip that has as many cities as possible. Uolevi wants to fly from Syrjälä to Lehmälä 
so that he visits the maximum number of cities. 
You are given the list of possible flights, and you know that there are no directed cycles in the flight network.

**Input**

The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n. 
City 1 is Syrjälä, and city n is Lehmälä. After this, there are m lines describing the flights. 
Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.

**Output**

First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. 
You can print any valid solution. If there are no solutions, print "IMPOSSIBLE".

Constraints : 
    2≤n≤10^5
    1≤m≤2⋅10^5
    1≤a,b≤n

Example : 
Input:
5 5
1 2
2 5
1 3
3 4
4 5

Output:
4
1 3 4 5
*/
   
#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
     
using namespace std;

vi v[100005];       
int inDegree[100005];       // Number of edges coming towards an node
vi result;
int parent[100005];
int dp[100005];
/*
	Approach : I tried it for over 20 times. Studied various topics. Came through this one
			   Using TopoSort in this does this in O(n+m) which was required. Now
			-> We sort all the edges topologically, because we are using DP in this ques and our condition is max(dp[par_node]+1, dp[curr_n])
			   So topological sort will ensure that dp[curr_node] is directly associated with its par_node, ie, we already have calculated 
			   dp[par_node] in order to calculate dp[curr_node]. Thats what topoSort does. It assigns the nodes in the order they should be 
			   processed. And then, we simply run two loops, one on the toposorted vec, another for children.
			-> We should initialize the dp[] array with INT_MIN and then check iff it is possible to reach the end node from 1. If 
			   dp[end_node] <= 0 --> Not possible, because if it was, then the distance would have changed from INT_MIN to dp[1] + 1;
*/
void khan(int n){
  priority_queue <int, vi, greater <int> > q;

  for(int i=1; i<=n; i++){
    if(inDegree[i] == 0)
      q.push(i);
  }
     
  while(!q.empty()){
    int a = q.top();
    result.pb(a);
    q.pop();

    for(auto u : v[a]){
      inDegree[u]--;
      if(inDegree[u] == 0)
      q.push(u);
    }
  }
}

int main(){
  int n, m;
  cin>>n>>m;
  
    for(int i=1;i<=n;i++)
        inDegree[i] = 0, dp[i] = INT_MIN, parent[i] = -1;
	
	dp[1] = 1;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        inDegree[b]++;
    }
     
  	khan(n);
	
	for(auto u : result){
		for(auto x : v[u]){
			if(dp[x] < dp[u] + 1)
				dp[x] = dp[u]+1, parent[x] = u;
		}
	}
	
	if(dp[n] <= 0)
		cout<<"IMPOSSIBLE\n";
	else{
		int y = n;
		vi path;
		while(parent[y] != -1){
			path.pb(y);
			y = parent[y];
		}
		if(y == 1)
			path.pb(1);

		reverse(path.begin(), path.end());
		cout<<dp[n]<<"\n";
		for(auto u : path)
			cout<<u<<" ";
		cout<<"\n";
	}
} 