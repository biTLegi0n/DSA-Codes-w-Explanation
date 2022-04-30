#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Insertion Sort
 *
 * @param arr
 * @param n
 *
 * Insrtion sort is not the ideal sorting algorithm but it is better than bubble and selection sort.
 * Here, I select a number and make sure that it reaches its destination, ie, inserts it to its right
 * ful place. Here i go, I select a number, and then shifts all the numbers which are on its LHS but are
 * larger than it. we shift all those numbers to one step right and then when we encounter a number which
 * is actually smaller than or equal to the current number, we stop and insert this current to that place.
 * The hole here represents current number and we are swapping it to find the right place for our current.
 *
 * The bEST case TC : O(n)
 * Worst and Avg case : O(n^2)
 */
void insertion_sort(vector<int> &arr,int n){
    for(int i = 0; i<n; i++){
        int temp = arr[i];
        int hole = i;
        // This loop shifts all those elements which are larger than our current elements to the right.
        while(hole>0 and arr[hole-1]>temp) {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = temp;
    }
}

int main(){
    int n; cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    insertion_sort(arr,n);
    for(auto u : arr) cout<<u<<" ";
    cout<<"\n";
}