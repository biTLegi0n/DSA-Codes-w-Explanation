#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Merge Sort
 *
 * This algorithm is the one that we need to emphasize more. The analysis of this is done in later
 * parts but first understand its working.
 * 1. In this algorithm, we use divide and conquer strategy. We divide the array, sort the individual
 *    two parts, and then merge the two sorted parts using two pointers and basic comparisions.
 *      - Divide : To divide, we get a mid, and divide the current array into two, left and right array
 *                 where left contains elements from [0,mid] and right contains elements from (mid,end].
 *                 After dividing the current array, we further divide these left and right subarrays
 *                 until we have one element left in each, which is its base case. After calling the
 *                 fun recursively on both the halves, we call the merge function.
 *      - Merge  : In merge function, we merge the left and right halves and overwrite the values in
 *                 A. While overwriting, we compare the current pointer values. As can be seen from
 *                 below code, we maintain three different pointer, i for left, j for right, and k for A
 *                 and increment them accordingly. After one of the left or right is finished, we run two
 *                 more while loops to make sure that the remaining elements are included as well.
 *
 * Analysis : -----------------------------------------------------------------------------------------------------
 *
 * 1. Stable Algorithm : If we are sorting a pair with this algorithm, it maintains their relative order.
 *                       That means, if we have a pair (2,5) before (2,3), then after sorting, (2,5),(2,3)
 *                       (2,5) would still be before (2,3) irrespective of the fact that the second element
 *                       is smaller in (2,3).
 * 2. Not inplace      : Space complexity of Merge sort is O(n) if we clear the memory that has played its role.
 *                       If we donot clear the memory that has been used, we will have space complexity of O(nlogn)
 * 3. Time complexity  : TC of merge sort in worst case is O(nlogn), in average and best also, it is O(nlogn)
 *
 *
 * @param left
 * @param right
 * @param arr
 */
void merge(vector<int> &left, vector<int>&right, vector<int> &arr){
    int i = 0, j = 0, k = 0;
    while(i<left.size() and j<right.size()){
        if(left[i]<=right[j])
            arr[k]=left[i],i++,k++;
        else
            arr[k]=right[j],j++,k++;
    }
    while(i<left.size()) arr[k]=left[i],i++,k++;
    while(j<right.size()) arr[k]=right[j],k++,j++;
}

void merge_sort(vector<int> &arr, int n){
    if(n<=1) return;

    int mid = n/2;
    vector<int> left, right;
    for(int i = 0; i<mid; i++) left.push_back(arr[i]);
    for(int i = mid; i<n; i++) right.push_back(arr[i]);

    merge_sort(left,left.size());
    merge_sort(right,right.size());
    merge(left,right,arr);
}

int main(){
    int n; cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    merge_sort(arr,n);
    for(auto u : arr) cout<<u<<" ";
    cout<<"\n";
}