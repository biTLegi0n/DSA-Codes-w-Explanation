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

int arr[100005];
int seg[400020];
int lazy[400020];

/* This code is for finding the sum of all values in range (a-b) with updation allowed. Initial values of arr[] is all 0s.      

    Approach : Lazy propogation is a technique which is used to update values in a range in O(logn) time rather than in O(nlogn). In this
               method, we only update the values which are needed at the moment. A new tree array, LAZY is maintained which stores the 
               record of whether a current element of array be updated or not. We keep the record there, and if needed, we update it 
               accordingly for all of its children nodes. And pass its legacy to its immediate children. 
               NOTE: we are not actually updating every element of arr, but we are manipulating the result and storing the update query
                     in the corresponding node of LAZY
               
               There are few important points to note in its code : 
               1 -> In each of the query and update function, the first thing we check is if there is any update remaining on current si.
                    we check this in LAZY, if lazy[si] != 0, then that means nodes below si, or current (ss-se) range has a pending update.
                    So we first finish updating the corresponding node in seg[], and then pass the update val, to the immediate children 
                    of lazy[si]. In this way, we got what we wanted without changing all the nodes within the range. So the first thing is
                    TO CHECK IF WE HAVE ANY PENDING UPDATES.
               
               2 -> After checking this, query and update function works in the same way they used to. The only difference will be in Update
                    function next. That change is that if the to_be_updated_query falls in our (ss-se) range, we update the corresponding 
                    node in seg[] and will mark a pending update in lazy[]. 
                    NOTE: The value in seg[] is updated as (number of nodes in range)*(val) and in lazy[], val is stored as pending update
                          Next, this val is used to determine the change in answer of seg[] for all the elements in (ss-se).  
*/

void build(int si, int ss, int se){
  if(ss == se){
    seg[si] = arr[ss];
    return;
  }

  int mid = (ss + se)/2;

  build(2*si, ss, mid);
  build(2*si + 1, mid+1, se);

  seg[si] = seg[2*si] + seg[2*si + 1];
}

int query(int si, int ss, int se, int qs, int qe){
  
  if(lazy[si] != 0){
    int dx = lazy[si];
    lazy[si] = 0;
    // dx*..... is added in already existing value of seg[si]
    seg[si] += dx*(se - ss + 1);
    
    // If (ss == se) then that means we are at last node, so no children
    if(ss != se)
      lazy[2*si] += dx, lazy[2*si+1] += dx;
    // dx..... is added, not replaced.
  }
  
  if(ss > qe || se < qs)
    return 0;
  
  if(ss >= qs && se <= qe)
    return seg[si];
  
  int mid = (ss + se)/2;

  return query(2*si, ss, mid, qs, qe) + query(2*si+1, mid+1, se, qs, qe);
}

void update(int si, int ss, int se, int qs, int qe, int val){
  if(lazy[si] != 0){
    int dx = lazy[si];
    lazy[si] = 0;
    seg[si] += dx*(se-ss + 1);

    if(ss != se)
      lazy[2*si] += dx, lazy[2*si+1] += dx;
  }

  if(ss > qe || se < qs)
    return;

  if(ss >= qs && se <= qe){
    int dx = val;
    seg[si] += dx*(se - ss + 1);

    if(se != ss)
      lazy[2*si] += dx, lazy[2*si + 1] += dx;
    return;
  }

  int mid = (ss + se)/2;
  update(2*si, ss, mid, qs, qe, val);
  update(2*si + 1, mid+1, se, qs, qe, val);

  seg[si] = seg[2*si] + seg[2*si+1];
}

int main()
{
  // FAST;

  int n, q;
  cin>>n>>q;
  
  build(1, 1, n);

  while(q--){
    int choice, a, b, val;
    cin>>choice;
    if(choice == 2){
      // Increase/Update
      cin>>a>>b>>val;
      update(1, 1, n, a, b, val);
    }
    else{
      // Sum of range (a-b)
      cin>>a>>b;
      cout<<query(1, 1, n, a, b)<<"\n";
    }
  }
}