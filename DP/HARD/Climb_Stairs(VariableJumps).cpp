#include <iostream>
#include <string.h>
using namespace std;

int dp[25];
/*
  try to look for the base case and then build up the dp. In this case, we can see that base case is when we are already at 6.
  Then there is only one way. So we build other arrays from that we move backwards and build the array.
*/
int cs(int arr[], int n){
  memset(dp, 0, sizeof(dp));
  dp[n] = 1;
  for(int i = n-1; i>=0; i--){
    for(int j = 1; j<=arr[i] and i+j <= n; j++)
      dp[i] += dp[i+j]; 
  }
  return dp[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}