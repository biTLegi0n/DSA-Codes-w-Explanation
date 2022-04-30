#include <bits/stdc++.h>
using namespace std;
/**
 * @brief This is a nice example of using bucket sort problem. Here, we use the same concept that is used in bucket sort algorrithm.
 *        In bucket sort, we maintains 2d arrays, in which the lists contains all the elements in a range and we then sort those lists
 *        using any other sorting algorithm (which could be any, we believe that sorting a smaller array will be less time consuming than
 *        sorting a larger one).
 *              Here, in this problem, we dont have have such 2d array, instead, in a range, we save the maximum and minimum element
 *        because they will be responsible for our answer.
 *        The main problem that i faced during this problem is while finding the range, coz i didn't understand how we do that. It is found
 *        by finding the average difference in between the two gaps, or the array elements, and since we know that the maximum gap has to be
 *        greater than or equal to the average gap, therefore, qw find the average gap, and that acts as the deciding factor that decides
 *        that in which bucket current element will fall. We find the bucket index by subtracting the minimum element and dividing by avg.
 *
 * @param A
 * @return int
 */
int maximumGap(const vector<int> &A) {
    if(A.size()<2) return 0;
    int n = A.size();
    int mini = INT_MAX, maxi = -1;
    for(auto u : A) mini = min(mini,u), maxi = max(u,maxi);
    int avg = ceil(double(maxi-mini)/(n-1));

    vector <int> bucket_min(n-1,INT_MAX);
    vector <int> bucket_max(n-1,-1);

    for(int i = 0; i<n; i++){
        if(A[i]==mini or A[i]==maxi) continue;
        int idx = (A[i]-mini)/avg;
        bucket_min[idx] = min(bucket_min[idx],A[i]);
        bucket_max[idx] = max(bucket_max[idx],A[i]);
    }

    int prev = mini;
    int ans = 0;
    for(int i = 0; i<n-1; i++){
        if(bucket_max[i]==-1) continue;
        ans = max(ans, bucket_min[i]-prev);
        prev = bucket_max[i];
    }
    ans = max(ans,maxi-prev);
    return ans;
}
