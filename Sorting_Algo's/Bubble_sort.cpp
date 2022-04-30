#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Bubble Sort
 *
 * @param arr
 * @param n
 *
 * This article is improved Bubble sort with 2 improvments that will be discussed later. In bubble sort,
 * we iterate the whole array n-1 times(in which the array is guarenteed to be sorted) and in each
 * iteration, we compare the adjacent elements and swap the two if jth element is larger than j+1th
 * In each iteration, one element is guaranteed to be at its sorted place. ie, if the maximum element
 * is at the front, then by comparing with the adjacenet and adjacent, in that iteration, that element
 * sent at the very last and it stays there. So in next iteration, we only need to compare the remaining
 * n-1 elements.
 *
 * IMPROVEMENT 1 : Since i just explained that in each iteration, one element is sent to its correct
 *                 sorted place, therefore, in the next iteration, we only need to compare the remaining
 *                 n-i elements.
 * IMPROVEMENT 2 : iF the array is already sorted, then we dont need to make extra iterations and we can
 *                 simply break on the loop.
 *
 * It is inplace sorting algorithm with O(n^2) time complexity.
 */
void bubble_sort(vector<int> &arr,int n){
    for(int i = 0; i<n-1; i++){
        bool flag = false;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]),flag = true;
        }
        if(!flag) break;
    }
}

int main(){
    int n; cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    bubble_sort(arr,n);
    for(auto u : arr) cout<<u<<" ";
    cout<<"\n";
}