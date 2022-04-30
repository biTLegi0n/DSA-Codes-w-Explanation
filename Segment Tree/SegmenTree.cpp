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

int arr[100005];
int seg[400020];

/*
    Approach : One of the most Important and Difficult topic. In segment tree, we break up a query into smaller queries and then 
               solve it in O(logN) time(This time is of 'query' function). We basically have three operations in this. 
               1. BUILD : This function first of all, fills the seg[] array according to our question, ie if we are asked to find the
                          min, we use seg[si] = min(.......), likewise for max, sum, diff etc. We see 
                            -> "si" is segment index, which is the index of segment array, or tree where we are currently present.
                            -> "ss" is segment start, which is almost always 1. It is the first node which is answer to range q (1-n)
                            -> "se" is segment end, which is almost always n, like ss. it also points to first node.
                         We recursively call the function by passing 2*si and 2*si + 1. When we make our segment tree, we give numbers
                         to nodes in a way such that, left child is always 2*(current sgement index) and right child is 
                         always 2*(currentsi)+1. Thus we call the build function to left and right child. When it reaches the last node
                         where range_left == range_right, we only have a single element left. Thus will be the direct answer, so we directly
                         store it in seg[si]. After these two call, we have one last statement, which is assigning seg[si] = what we need
                         we assign the current index of segment tree a value which is based on its left and right child. 

              2. UPDATE : This function is used when any value in the array is updated. Because any alteration in values of array leads to
                          differnt answers to the queries, therefore, this function is made, like build function, it updates the values
                          which are altered due to the updation in the array. But, unlike build function, we only visit the specific nodes 
                          based on the position of the element. ie if the position altered is 2 then will not go to range 3-5 or so. Thus,
                          before calling the function, we check whether we have to go to left or to right child. Once we reach our element/node
                          we update it in arr[], update the value of seg[si], and then return. And at the last, we keep on updating every
                          value of seg[si] during backtracking of the recursion.
                          NOTE : We can also update the value in main function only, and then we only had to alter the nodes affected 
                                 by that change. See the function.
               
               3. Query : This function find the actual value of the query asked. There are a few thing worth noting in this. We see in the
                          function that the first condition is that if (se < qs || ss > qe) we ignore that query. ie that particular query
                          is of no good use to us, so to ignore, we return accordingly, like if we are finding MIN, we return INT_MAX, 
                          if finding MAX, we return INT_MIN, and if sum, we return 0. According to second condition, if the current (ss,se)
                          lies completely in the range asked to us, we directly return that query's value, because that query will have a role
                          to play in finding the final answer.
                          NOTE: The final answer is stored in si = 1, all other nodes will play their part in finding the answer. 
                          After this, we just find the mid, and call the function on left and right child, applying the required operation
                          on both of them. 
*/

void build(int si, int ss, int se){
    if(ss == se){
        seg[si] = arr[ss];
        return; // This return call is important, else the function will keep going and will never end.
    }

    int mid = (ss + se)/2;
    build(2*si, ss, mid);
    build(2*si + 1, mid+1, se);

    seg[si] = seg[2*si] + seg[2*si + 1];
    //        left child  right child
}

void update(int si, int ss, int se, int pos, int num){
    if(ss == se){
        arr[pos] = num;
        seg[si] = num;
        return;     // This return is important to avoid overflow. As it is important to stop the function. 
    }

    int mid = (ss + se)/2;

    if(pos <= mid)
        update(2*si, ss, mid, pos, num);
    else    
        update(2*si + 1, mid+1, se, pos, num);
    
    seg[si] = seg[2*si] + seg[2*si +1];
}

int query(int si, int ss, int se, int qs, int qe){
    if(se < qs || ss > qe)
        return 0;
    if(ss >= qs && se <= qe)
        return seg[si];
    
    int mid = (ss + se)/2;
    return query(2*si, ss, mid, qs, qe) + query(2*si + 1, mid+1, se, qs, qe);
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++)
        cin>>arr[i];
    
    build(1, 1, n);

    int q;
    cin>>q;
    while(q--){
        cout<<"Choose your Query\n1 : Update\n2 : Find between L and R\n";
        int a;
        cin>>a;
        if(a == 1){
            int pos, x;
            cout<<"Enter the Position and new value.\n";
            cin>>pos>>x;
            update(1, 1, n, pos, x);
        }
        else
        if(a == 2){
            int l, r;
            cout<<"Enter the range : ";
            cin>>l>>r;
            cout<<"Elemnts at l and r are "<<arr[l]<<" & "<<arr[r]<<"\n";
            cout<<"The sum of this range is :";
            cout<<query(1, 1, n, l, r)<<"\n";
        }
    }
}