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
    Approach: Another application of Knapsack, particularly SubSetSum. We initialize the matrix in the same manner but this time
                matrix will hold the count of subsets having sum equal to 'j'. Thus we don't take OR(||) instead we keep on adding
                the values and finally we return dp[n][sum]. Keep in mind to initialize the matrix's first row and coloumn seperately

*/
int count_subset_sum(int a[], int n, int sum){
    int dp[n+1][sum+1];

    //initialization (seperate, its important to do it seperately, else matrix will be wrong)
    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;
    for(int j = 1; j<=sum; j++)
        dp[0][j] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(a[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
            // This is the only difference in this code :)
                dp[i][j] = dp[i-1][j - a[i-1]] + dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    cin>>n>>sum;
    int arr[n];;
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    cout<<count_subset_sum(arr, n, sum);
}