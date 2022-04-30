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
    Approach : This algorithm is used to return the size of LIS but not the LIS array.
                Its time Complexity is O(nlogn) but we cannot have the array from this algo
    What we basically do in this is that we check with the last element of the vector, if it is greater than the current element
    of array, we add the current element, a[i] to the vector and if the last element is smaller, then we have to replace the 
    current element, a[i] with any number just greater than that.(i.e we use upper_bound(a[i]) ).
    NOTE : we have no intention to keep the LIS, our main focus is to find the length of LIS. So, we dont care if replacing any 
            number in vector disturbs our LIS, its just that it wont change the length.

    IMP NOTE : If we need to find length of Strictly Incr. we have to use LOWER_BOUND. If we have to find only increasing, we use UPPER_BOUND
    For MORE : https://www.youtube.com/watch?v=qW1O1a40-No
*/

int LIS(int a[], int n){
    vi v;
    v.pb(a[0]);         // At first, we need to have something in our vector so that we can compare a[i] with it

    for(int i = 0; i<n; i++){
        if(a[i] < *(prev(v.end()))){         // If a[i] is smaller than the last element of vector, we replace this with any 
            int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();        // element just greater than a[i] ::-> LowerB as strictly Incr
            v[pos] = a[i];
        }
        else
        if(a[i] > *prev(v.end()))           // If a[i] is greater, then we should add it in the vector, cause it increases the Length
            v.pb(a[i]);
    }
    return v.size();
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];

    cout<<"Length of LIS is : "<<LIS(a, n)<<"\n";
}