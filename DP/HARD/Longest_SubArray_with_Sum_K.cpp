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
    Approach : This is a problem where we need to find the length of Longest Subarray (contigous) with sum K. In this algorithm
               we keep on moving forward, starting from index 0, and will keep a sum variable in which we will add every element
               We also keep a map of (sum, index) which tell us that this particular 'sum' was achieved on this 'index'
               -> iF after adding a particular element, we get the sum 'k', then we have a subarray, which is of maximum length
                  till now, so we will update our maxLen variable which holds the answer
               -> iF this sum do not exist in map, we add this sum with the index it is achieved on
               -> iF we have (sum-k) in map, than that means that elements till now sum up to 'sum' and we have some elements whose 
                  sum is 'sum-k' that means that elements_till_now - elements_with_sum_(sum-k) => elements _with_sum_k. That is, either
                  way we have a subarray which sum up to 'k' (It is the remaining subarray, different from the one whose sum is (sum-k))
*/
/*
    Similiarly, in this question, with a little variation, we can also find the number of subarrays having sum equal to k. To do so, we 
    need to update the count, each time we get a 'k' or 'sum-k' and store accordingly i map.
*/
int Length_Max(int n, int arr[], int k){
    int maxLen = 0;
    int sum = 0;

    map <int, int> m;

    for(int i = 0; i<n; i++){
        sum += arr[i];

        // Since this started from index 0, thus if sum at this elem is == k, then it will be maximum till now
        if(sum == k)
            maxLen = i+1;
        
        if(m.find(sum) == m.end())
            m[sum] = i;
        
        if(m.find(sum - k) != m.end()){
            if(i - m[sum-k] > maxLen)
                maxLen = i - m[sum-k];
        }
    }
    return maxLen;
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int a[n+1];
    for(int i = 0; i<n; i++)
        cin>>a[i];
    int k;
    cout<<"Enter the sum : ";
    cin>>k;

    cout<<"Length of Max Subarray with sum k is : "<<Length_Max(n, a, k);
}