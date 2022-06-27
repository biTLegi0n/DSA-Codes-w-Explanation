#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Did it click something??? You studied this concept in Algo's. We have to use the existing array as hash table.
 *        in questions where we only have elements from [1,n] or where we need to deal with only them, we use the existing
 *        array as hash since there, the if we jump to a position arr[i], we will land somewhere in the array only...
 *        Now, here we need to search for the first positive element which does not exists in the array.
 *        We can claim that if an element does exists in the array, then we can leave a mark by accessing any position from that
 *        element and the mark will be a negatioon of the element at that position. I mean if arr[i] exists, then mark arr[arr[i]] 
 *        as negative. This way, we can mark all the numbers in range [1,n] existing in the array and indices of only those which 
 *        does not exists in the array remains.
 *
 *          -> Also note that we are setting all the negatives = N+1 since we dont need to deal with them...
 *
 * @param arr
 * @return int
 */
int firstMissingPositive(vector<int> &arr) {
    // Just as we were getting the vibes, this questions is to be solved by using
    // the array as a hash table

    // Setting all the negatives equal to n+1, since negative numbers will interrupt with the answer.
    for(int i = 0; i<arr.size(); i++) {
        if(arr[i]<=0) arr[i] = arr.size()+1;
    }
    for(int i = 0; i<arr.size(); i++){
        if(abs(arr[i])<=arr.size())
            arr[abs(arr[i])-1] = -abs(arr[abs(arr[i])-1]);
    }
    // for(int i = 0; i<arr.size(); i++) cout<<arr[i]<<" ";
    // cout<<"\n";
    for(int i = 0; i<arr.size(); i++)
        if(arr[i]>0) return i+1;
    return arr.size()+1;
}