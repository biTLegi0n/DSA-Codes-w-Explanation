#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Selection Sort
 *
 * @param arr
 * @param n
 *
 * It is another easiest sorting algorithm. You can remember its functions with its name. It selects
 * the minimum element in each iteration and swaps it with its right position, ie, in each iteration
 * we consider the current element as the minimum element and then compare all the elements in front
 * of it, and find the element which is the minimum, and swap it with the initial position.
 *
 * It is inplace sorting algorithm with O(n^2) time complexity.
 */
void selection_sort(vector<int> &arr,int n){
    for(int i = 0; i<n; i++){
        int mini = arr[i],ind=i;        //setting current element and position as minimum
        for(int j = i+1; j<n; j++){
            if(arr[j]<mini) mini = arr[j],ind=j;        // finding next minimum
        }
        swap(arr[i],arr[ind]);
    }
}

int main(){
    int n; cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    selection_sort(arr,n);
    for(auto u : arr) cout<<u<<" ";
    cout<<"\n";
}