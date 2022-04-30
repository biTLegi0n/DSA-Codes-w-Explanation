#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

/*
    Approach : We keep on adding the sum untill it remains positive because only then it could be a maximum.
               The thing is, if we keep on adding arr[i] to sum, without resetting it to 0 when it is negative, that
               would alter our future chances of having an ans. For ex : {-2, -3, 4} :: If we run a loop and keep on
               adding the  values to sum, we will have values : [-2, -5, -1] and ans as -2 while taking {4} as a subset
               we can have 4 as an answer (Which is CORRECT). Thus, whenever we have a negative value of sum, we reset
               it to 0, so that when we encounter any positive value, we can set sum equal to that and update our ans
*/

int kaden(int arr[], int n){

    int sum_till_now = 0, ans = INT_MIN;

    for(int i = 0; i<n; i++){
        sum_till_now += arr[i];

        if(sum_till_now > ans)
            ans = sum_till_now;
        else
        // So that when we have a positive value, we can set sum equal to that :: which would be true if we'd take a set of only that num
        if(sum_till_now < 0)
            sum_till_now = 0;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    cout<<kaden(arr, n);
}