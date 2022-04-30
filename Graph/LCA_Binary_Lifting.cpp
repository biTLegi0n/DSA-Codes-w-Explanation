#include<bits/stdc++.h>
#define vi vector <int>
#define vl vector <long long>
#define vc vector <char>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vi v[100005];
// For greater values, its better to keep the dimesions upto 32.
int par[10005][14];     //14 (13 + 1) is taken according to the constraints, ie maximum log2 allowed
int level[10005];

/*
    Approach : This is an Important Tree algorithm. In continuation of LowestCommon_Ancestor, this is a better technique than that.
               It finds the LCA in O(logN) and Overall Time Complex. is O(NlogN). We use Dp and Binary movements in this approach.
               The two main points in this whole Algorithm are : 
               ->  Using Dp to fill the parent matrix. We first initialize the 0th coloumn. Because 0th parent is direct parent of 
                   any node, as 2^0 = 1, so parent at distance 1 is direct parent only. We then use this to find the next, and then
                   next to find his next and so on. We observe one thing that dp[node][i] (it means parent of node at distance 2^i)
                   is dp[node][i-1] + dp[dp[node][i-1]][i-1]. in simple words, lets say that we want to find 2^5th parent of node, 
                   then that will be 2^4th parent of node + 2^4th parent of this later node. We see that 32 could be written as
                   2^4(16) + 2^4(16). A distance of 32 can be covered in two steps, one of 16 and another of 16 as well. And we see that
                   16 is nothing else but 2^4. One distance of 16 will be from node, thus dp[node][i-1] = 16 and then from this ancestor
                   to a node of 16 distance, will be the final node at distance 32.
               ->  After filling up the parents[]/dp[] matrix, we process queries. We swap the nodes, if Level[a] > Level[b]. We need to
                   keep 'a' on top of 'b', just for ease in understanding and avoiding confusions. After this, we find the difference b/w
                   their levels and until the difference is >0, we run a loop, which constantly moves upward to the maximum allowed
                   power of 2. We update the diff and 'b' accordingly. After this, we just check two things.
                    1   if a == b, we are already on LCA
                    2   We run a loop from the maximum power of 2 that we can take(accn to our constraints), check iff parent at that 
                        pow exists or not, and if exists then is par[a][i] == par[b][i], if these two are equal, then there might
                        be a case that we have left our LCA behind, so we dont consider this case as well. We see that the node we landed on
                        should not be the same for both, and it should exist, Then by the end of for loop, we will be on a node, one distance
                        below the LCA or at a child of LCA. 
*/

void dfs(int node, int parent, int lvl){
    par[node][0] = parent;
    level[node] = lvl++;

    for(auto u : v[node]){
        if(u != parent)
            dfs(u, node, lvl);
    }
}

void fill_par(int n){

    dfs(1, -1, 0);
    /* We need to take care while writing these loops. The loop for powers of 2 is written first Because we need to fill all the 
       powers of a node, ie all the ancestors we need to check. If the graph has a cycle, then it can have many ancestors, as the cycles
       never ends. So we first write the power loop and then node loop.
    */
    for(int j = 1; j<=13; j++){
        for(int i = 1; i<=n; i++){
            if(par[i][j-1] != -1){
                int intermidiate = par[i][j-1];
                par[i][j] = par[intermidiate][j-1];
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i = 1; i<=n; i++)
        for(int j = 0; j<=13; j++)
            par[i][j] = -1;

    for(int i = 1; i<n; i++){
        int a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    fill_par(n);

    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;

        if(level[a] > level[b])
            swap(a, b);
       
        int diff = level[b] - level[a];
        while(diff > 0){
            int i = log2(diff);
            b = par[b][i];
            diff = diff - pow(2, i);        // poww(2, i) is better written (1<<i)
        }

        if(a == b)
            cout<<"LCA is "<<a<<"\n";
        else{
            for(int i = 13; i>=0; i--){
                if(par[a][i] != -1 && (par[a][i] != par[b][i]))
                    a = par[a][i], b = par[b][i];
            }
            cout<<"LCA is : "<<par[a][0]<<"\n";
        }
        
    }
}