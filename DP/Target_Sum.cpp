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
    Approach : This is a problem in which we have to assign +/- signs before every number in the array such that its sum becomes 
                equal to a target. in order to do so, we can approach the ques in this way :: 
                    - We seperate the positives and negatives and thus makes two subsets, such that S1 - S2 = Target and also 
                      we know that S1 + S2 = Total_Sum. Therefore, solving these two, we end up with finding subsets with 
                      Sum = (Target + Total_sum)/2

                But there are some corner cases as well, such as
                    - When there are zeroes in our array, we can either assign + or - to them but that won't change anything 
                      thus, counting them in dp[][] array would not make sense. Hence we count them independently and avoid 
                      considering them in dp[][] array & at last we would return pow(2, count_zero) * dp[n][sum]
                      That's because we can make two choices on 0, + or - and both would give the same results      
*/
int target_sum(int num[], int n, int target){
    
    int sum = 0, count_zero = 0;
    for(int i = 0; i<n; i++){
        sum += num[i];
        if(num[i] == 0)
            count_zero++;
    }

    if(sum < target)
        return 0;
    if((sum+target)%2 != 0)
        return 0;
    
    sum = (sum+target)/2;
    int dp[n+1][sum+1];

    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;
    for(int j = 1; j<=sum; j++)
        dp[0][j] = 0;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            /* We avoid considering 0 in dp as that would be done independently
                if we'd consider it in dp, that won't make sense as choices will be either consider or leave
                while we know that we can make any choice and still the answer will remain same. */
            if(num[i-1] == 0)
                dp[i][j] = dp[i-1][j];
            else
            if(num[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j - num[i-1]] + dp[i-1][j];
        }
    }
    return pow(2, count_zero) * dp[n][sum];
}

int main()
{
    int n, target;
    cout<<"Enter the size of array : ";
    cin>>n;
    int num[n];
    cout<<"Enter the target sum : ";
    cin>>target;
    cout<<"Enter the array : ";
    for(int i = 0; i<n; i++)
        cin>>num[i];
    cout<<target_sum(num, n, target); 
}