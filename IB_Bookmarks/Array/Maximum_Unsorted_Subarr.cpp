#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * In this problem, At first, i wrote a solution using a temp array which is sorted and then comparing
 * the elements of arr and temp, but that solution actually crossed the memory limit. Thus, the O(1)
 * and O(n) solution is explained below.
 *  - We start by finding the 'start' and 'end' index of that subarray which needs to be sorted. Now,
 *    how we do that?? We simply run a loop from the start and search for a element which is less than
 *    its neighbour. ie, arr[i]<arr[i-1]. Since, the array is sorted in ascending order, then all the
 *    elements has to be in ascending order. Therefore, an element which is smaller than its neighbour
 *    is odd. So we mark the 'i' as the start index. Similiarly, we start from the last and look for
 *    such odd pair. We search for a pair where arr[i]<arr[i-1]. Meaning, a number which is smaller than
 *    its next neighbour. Since, in increasingly sorted array, this is not right. Therefore, we will have
 *    the start and end indices. Now, this is not enough. Because there could be cases like
 *    [1,2,3,4,1,2,3,5,6,7]. In such cases, we can see that in the window, the minimum element is 1. So
 *    we need to take the whole window that makes the entire array sorted. Thus the answer will be [1,6]
 *    ie, we need to shift the start. So to check that, we find the minimum and maximum element in the
 *    window and then check for the smallest element greater than the minimum in [0,start) and smallest
 *    element which is greater than the maximum in (end,n). After changing the start and end, we can return.
 *
 * @param arr
 * @return vector<int>
 */

vector<int> subUnsort(vector<int> &arr) {
    int start = -1, end = -1;
    for(int i=0;i<arr.size()-1;i++) if(arr[i+1]<arr[i]) {start = i; break;}
    int max1 = INT_MIN;
    for(int i=arr.size()-1;i>start;i--) if(arr[i]<arr[i-1]) {end=i;break;}
    int maxw=INT_MIN, minw=INT_MAX;
    for(int i=start;i<=end;i++) maxw=max(maxw,arr[i]),minw=min(minw,arr[i]);
    for(int i=0;i<end;i++) if(arr[i]>minw) {start=i;break;}
    for(int i=arr.size()-1;i>end;i--) if(arr[i]<maxw) {end=i;break;}

    if(start==-1) return {-1};
    return {start,end};
}
