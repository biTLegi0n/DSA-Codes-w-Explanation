// In every step, we choose a node whose inDegree is 0
// inDegree of a node is number of edges coming towards it. I mean, inDegree of source node will be zero

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
/**
 * @brief A wonderful problem of this concept : https://leetcode.com/problems/minimum-height-trees/
 */

//We don't even need visited array in this :)
vi v[100005];
int inDegree[100005];       // Number of edges coming towards an node
vi result;
/*
    Accroding to Kahn's algorithm, each time we take a node having indegree = 0 and we remove all the edges
    linked to it. We repeat the process untill we finish all the nodes.
*/

bool khan(int n){
  // We take priority queue in place of queue in ques which demands lexicographically smallest toposort
  priority_queue <int, vi, greater <int> > q;

  // Initially we push all the nodes in queue having indegree = zero
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
  return (result.size() == n);      // Instead of explicitly checkking for cycles, we use this one line condition
                                    // If of FINAL vec is not equal to n, then graph is not DAG.
}

int main(){
  int n, m;
  cin>>n>>m;

    for(int i=1;i<=n;i++)
        inDegree[i] = 0;

    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        inDegree[b]++;
    }

    if(!khan(n))
      cout<<"Not a DAG, Contains CYCLE\n";
    else{
        for(int i=0;i<n;i++)
        cout<<result[i]<<" ";
    }
}