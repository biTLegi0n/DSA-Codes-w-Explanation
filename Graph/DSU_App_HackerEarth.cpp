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

int parent[100005];

/*  ==================== THEORY FOR DSU ====================

Disjoint Data Set are special data structures and frankly, the easiest one
They have only two operations, UNION/JOIN & FIND. 
    FIND : This operation usually find the Godfather of the tree/subtree. There is only one 
            Godfather of an subtree and that is stored in parent[]. 
            -- We use path compression to reduce the time complexity of finding that Godfather. Path compression 
               is recursively updating the parent[] values to the Godfather value and that's all
            Initally, we can fill the parent[] with either 'i' or '-1'. That is totally according to our need
            That is the best thing about DSU that we use the parent[] according to our need

    UNION/JOIN : This operation joins two subtrees by joining their Godfathers. We simply join them by changing their 
                 parent[] values. We also use this operation according to our need. Sometimes we simply join them, 
                 no matter who is bigger or smaller, sometimes we join them according to their order
                 -- UNION by Rank : This is another optimisation technique. In this, we maintain another array 
                    named RANK which contains the size of the subtree of every node. 
                    Union by rank always attaches the shorter tree to the root of the taller tree.
                    To implement union by rank, each element is associated with a rank. Initially a set has one element 
                    and a rank of zero. If we union two sets and 
                        ~ Both trees have the same rank – the resulting set’s rank is one larger
                        ~ Both trees have the different ranks – the resulting set’s rank is the larger of the two.
                    
                    Ranks are used instead of height or depth because path compression will change the tree's heights over time.

                Worst case complexity: O(LogN) 
    
    The only change in case of union by rank will be to maintain an RANK array and joining the Godfathers accordingly.
*/

// Path compression algorithm
int find(int a){
    if(a == parent[a])
    return a;

    int x = find(parent[a]);
    parent[a] = x;
    return x;
}

void join(int a, int b){
 
    a = find(a);
    b = find(b);

    if(a == b)
        return;
    else{
        if(a>b)
        parent[b] = a;
        else
        parent[a] = b;
    }
}

int main()
{
    FAST;

    int n, m;
    cin>>n>>m;
    
    for(int i = 1; i<=n; i++)
    parent[i] = i;

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        join(a,b);
    }
    for(int i = 1; i<=n; i++)
    parent[i] = find(i);

    for(int i = 1; i<=n; i++)
    cout<<parent[i]<<" ";
    cout<<"\n";

    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        if(find(a) == find(b))
            cout<<"TIE\n";
        else
        if(find(a) > find(b))
            cout<<a<<"\n";
        else    
            cout<<b<<"\n";
    }
}