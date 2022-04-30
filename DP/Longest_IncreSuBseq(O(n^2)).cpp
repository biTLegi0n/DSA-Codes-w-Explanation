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

int length[10005];
vi res;

// This code executes with O(n^2) which is not so good :(
/*  
    Approach : We simply run two loops, one for the number we are currently at, another from start till that number and with
                each iteration, we compared and set the max(length[i], length[j] + 1) as the new value of length[i]
    This might seem crazy but its easy to visualize on paper.
*/
/*
    This problem can also be converted to Maximum Sum Increasing SubSequence just by channging one condition
                    sum[j] + arr[i] > sum[i] ==> sum[i] = sum[j] + arr[i]
    As we are required to maintain and find the maximum sum, so, instead of maintaining length, we maintain sum
*/

int LISub(int a[], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[j] < a[i])
                if(length[j] + 1 > length[i])
                    length[i] = length[j] + 1;          // We can also do : max(length[i], length[j]+1)
        }
    }

    // After finding the LIS for each number, we can now find the maximum one
    int ans = 0, ans_index;
    for(int i = 0; i<n; i++){
        if(length[i] > ans)
            ans = length[i], ans_index = i;
    }
    
    // This is to print the LIS, we revert back from the maximum to 1 (By keep reducing the LIS by 1)
    int temp = ans;
    res.pb(a[ans_index]);
    for(int i = ans_index; i>=0; i--){
        if(length[i] == temp-1){
            temp -= 1;
            res.pb(a[i]);
        }
    }
    return ans;
}

int main()
{
    //FAST;

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];

    for(int i = 0; i<n; i++)
        length[i] = 1;

    int ans = LISub(a, n);
    cout<<"Length of Longest Increasing SubSeq is : "<<ans<<"\n";
    cout<<"That SubSeq is : ";
    reverse(res.begin(), res.end());
    for(auto u : res)
        cout<<u<<" ";
}