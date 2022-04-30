#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   I literally wasted a lot of time on this question with wrong approach. Actually i made a mistake of thinking that i have to
 *          apply binary search over the search space of answer directly. iNstead, that has to be done on the length. So the search space
 *          is the overall possible length. And due to that, this problem is replaced with the same as book allocation with the only change
 *          in the final return statement, where we multiply the rate to the final median length.
 *          Keep in mind, dont use the search space of answer, ie length*unit_time, instead, use the search space of length only!!!
 * @param mid
 * @param arr
 * @return int
 */

int isvalid(int mid, vector<int>&arr){
    int num_of_stud=0,sum=0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]>mid) return INT_MAX;
        sum += arr[i];
        if(sum>mid){
            num_of_stud++;
            sum=arr[i];
        }
        else
        if(sum == mid)
            num_of_stud++, sum=0;
    }
    if(sum>0) num_of_stud++;
    return num_of_stud;
}

int paint(int A, int B, vector<int> &arr) {
    long long low = 0,high=0;
    for(int i = 0; i<arr.size(); i++)
        high += arr[i];
    int res = -1;
    while(low<=high){
        long long mid = low+(high-low)/2;
        if(isvalid(mid,arr)<=A){
            res = mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    // This is the only change that we have in this and book allocation.
    return (((long long)res*(long long)B))%10000003;
}
