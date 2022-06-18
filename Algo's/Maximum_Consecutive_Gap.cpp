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
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        
        int maxi = -1, mini = INT_MAX, n = nums.size();
        for(auto u : nums) maxi = max(maxi,u), mini = min(mini,u);
        // Since there will be n-1 gaps in between the numbers, this will be the average gap between
        // any two numbers in the array.
        // NOTE : Its very important to take the upper value of average gap, or else we will have a runtime error
        // in the index of bucket that we will find in the next step.
        int avg_gap = (int)ceil((double)(maxi-mini)/(n-1));
        // To handle cases where all the elements are same!!!
        if(avg_gap == 0) return 0;      
        /*
        Now, we can allot all the numbers a bucket, by dividing them with this average gap. Now it 
        can be easily observed that by dividing any numbers with this average gap, it is sure to fall 
        in one of the (n-1) buckets that will be formed. 
        Taking the example 1, 
                
                [3, 6, 9, 1]      =>    avg gap = ceil[(9-1)/3] ~= 3
        Now we have to find the maximum gap, therefore, it will be >= average gap.
        Alloting the buckets : [[arr[i]-min]/average_gap], for all numbers of the array, this formula will result
                               in numbers that lie in a range, and thus the result for each can be considered as 
                               the bucket index.
                               
                [3-1]/3 = 0
                [6-1]/3 = 1
                [9-1]/3 = 2
                [1-1]/3 = 0
            
              0        1      2
            1___3    ____6  ____9
            
            Now as we said, the maximum gap will be greater than or equal to the average gap, therefore, the answer
            will not lie within a bucket because its gap between the maximum and minimum element will always be
            less than the average gap, for reference, consider in bucket 2nd, we had the bucket fully filled, then
            in that case, we would have 4 as the minimum and 6 as maximum and there difference be 2. So, even in 
            worst case, we have a difference 1 less than the average. So, for the question, we only need to check
            in between the buckets. Thus we only compare the difference between the maximum of one bucket and 
            minimum of next.
        */
        
        // Allocating the buckets and storing the maximum and minimum of each bucket 
        vector <int> bucket_max(n,-1), bucket_min(n,INT_MAX);
        for(int i = 0; i<n; i++){
            int index = (nums[i]-mini)/avg_gap;
            bucket_min[index] = min(bucket_min[index],nums[i]);
            bucket_max[index] = max(bucket_max[index],nums[i]);
        }
        
        // After filling the min and max arrays, we just need to compare...
        int prev = mini, ans = 0;
        for(int i = 0; i<bucket_min.size(); i++){
            if(bucket_max[i] == -1) continue;
            ans = max(ans,bucket_min[i]-prev);
            prev = bucket_max[i];
        }
        // We need to compare with the last element which is maximum...
        ans = max(ans,maxi-prev);
        return ans;
    }
};