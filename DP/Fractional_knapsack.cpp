#include <iostream>
#include <stdio.h>
#include <queue>
#include <iomanip>

using namespace std;
float ans;

/*
    APPROACH: We find the price/weight value of each item and then arrange them in descending order so that we can take the item 
              with max frac value first. So we priority_queue in this. Since this a greedy method, therefore, we try to get the maximum 
              from each step. Rest can be seen in code.
*/

void fractional(int arr[], int val[], int W, int n){
  
  priority_queue <pair <float, int>> q;

    // Pushing the {frac,index} pair in priority queue   
    for(int i = 0; i<n; i++){
        float frac = (float)val[i]/(float)arr[i];
        q.push({frac, i});
    }

    // We run the loop until the knapsack is full.
    while(!q.empty()){
        float frac = q.top().first;
        int i = q.top().second;
        q.pop();
        // Fill up the remaining weight and update the price accordingly.
        if(arr[i] >= W){
            float rem = W;
            W = 0;
            if(rem == 0)
                ans += arr[i]*frac;
            else
                ans += rem*frac;
            // Break from the loop, since after this step, knapscak if FULL
            break;
        }
        else{
            W -= arr[i];
            ans += val[i];
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n+1], val[n+1];

    for(int i = 0; i<n; i++)
        cin>>val[i];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    int W;
    cin>>W;
    fractional(arr, val, W, n);
    cout<<ans<<"\n";
}