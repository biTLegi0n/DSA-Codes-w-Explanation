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

/*
                                                ****Variation of Kadane's Algo****
    Problem : https://leetcode.com/problems/maximum-sum-circular-subarray/

    Approach : 
        So there are two case.
            Case 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
            Case 2. The second is that the subarray take a part of head array and a part of tail array.
        The maximum result equals to the total sum minus the minimum subarray sum.
        So the max subarray circular sum equals to
                max(the max subarray sum, the total sum - the min subarray sum)
        
        Proof of the second case

        max(prefix+suffix) = max(total sum - subarray)
                           = total sum + max(-subarray)
                           = total sum - min(subarray)

        ~Corner case~

        Just one to pay attention:
        If all numbers are negative, maxSum = max(A) and minSum = sum(A).
        In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
        According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
        So we return the maxSum to handle this corner case.

        ~Complexity~

        One pass, time O(N)
        No extra space, space O(1)

*/

int maxSubarraySumCircular(vector<int>& nums) {
    // We need to observe one simple thing in this. The maximum sum subarray corresponds to remaining minimum sum subarray. 
    // So if we multiply the whole array with -1 and then search for maximum sum subarray, that would eventually give us the 
    // minimum sum subarray. Changing the sign of the final answer would give us the minimum sum. 
    // And We can do this with the help of KADANE's algo
        
    int single_sum = 0, single_ans = 0;
    for(int i = 0; i<nums.size(); i++){
        single_sum += nums[i];
        
        if(single_sum < 0)
            single_sum = 0;
        if(single_sum > single_ans)
            single_ans = single_sum;
    }
    if(single_ans == 0){
        sort(nums.begin(), nums.end(), greater <int>());
        return nums.front();
    }

    // All the work done above was for the max subarray sum and work below will be for finding the min subarray sum and then using it in our favour

    for(int i = 0; i<nums.size(); i++)
        nums[i] *= -1;
    
    int sum = 0, temp_sum = 0, ans = -10000007;
    for(int i = 0; i<nums.size(); i++){
        temp_sum += nums[i];
        sum += nums[i];
        // cout<<"sum is : "<<sum<<" and temp_sum is : "<<temp_sum<<"\n";
        if(temp_sum > ans)
            ans = temp_sum;
        if(temp_sum <0)
            temp_sum = 0;
    }
    if(single_ans == 0 and ans<0)
        return ans;
    
    return max(single_ans, -1*(sum-ans));
} 

int main()
{
//   FAST;
    int n;
    cin>>n;

    vi v;
    for(int i = 0; i<n; i++){
        int k;
        cin>>k;
        v.pb(k);
    }
    cout<<"Maximum sum of a subarray is : "<<maxSubarraySumCircular(v);
}