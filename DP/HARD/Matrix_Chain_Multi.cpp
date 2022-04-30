#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

/*
    Approach: This is where the real struggle starts. In MCM, we have a set of matrices and we need to find the minimum cost of 
              operations to multiply them. We know that A*B*C(10x20, 20x30, 30x10) will have different costs of operations when 
              they are assigned different parenthesis ie (AB)C will have different cost of opn and A(BC) will have different. 
              Also, Cost of operations is found as AXB ==> 10x20x30 :: This is because we see that 10x20 blocks are multiplied with 
              30 coloumns and the resultant array AB will be of 10x30 dimensions.

              -> The dimensions are given in form of an array where dimensions of Ai are Arr[i-1]xArr[i]. Thus to find the minimum
                 cost of operations, we check for all the subproblems, putting parenthesis on all the valid positions and then 
                 finding the cost of operation for each subproblem and ultimately returning the min operations. 
              
              -> The base case is that if left >= right, we return 0, because there will be no array in this case.
              -> we run a loop from left to right and each time, this k will divide the array, we calculate the min_operations for 
                 array starting from 'l' and ending at 'k' and array starting from 'k+1' and ending at 'r'. Then we add the answers 
                 returned from these two calls and we finally add the cost of multipplying these two partitions as well which is 
                 arr[i-1]*arr[k]*arr[r] (as defined above (as the matrices would have dimensions : arr[i-1]xarr[k] & arr[k]xarr[r]))
                 
              -> Complexity of this Algo is O(n^3)
*/

int dp[1005][1005];

int mcm(int arr[], int l, int r){

    if(l == r)
        return 0;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    // This variable 'ans' when declared globally disturbs the answer. Therefore, it is important to declare this in mcm function only
    int ans = INT_MAX;
    for(int k = l; k<r; k++){
    // We can even directly set dp[i][j] = min(dp[i][j], ....) here by initializing dp[i][j] = INF
        int count = mcm(arr, l, k) + mcm(arr, k+1, r) + arr[l-1]*arr[k]*arr[r];
        if(count < ans)
            ans = count;
    }
    return dp[l][r] = ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    memset(dp, -1, sizeof(dp));
    cout<<mcm(arr, 1, n-1);
}
