#include <bits/stdc++.h>
using namespace std;

/**
 * @brief QuickSort
 *
 * This algorithm is considered the best and most of the predefined sorting techniques uses this one. Here, sorting
 * is done inplace. We consider a pivot element, whose speciality is that on the left hand side of this pivot are all
 * elements which aer smaller than it and on the right hand side are the elements which are greater than it. And in
 * each recursive call, we call this partition function and fetches the pivot index. While fetching, we swap and
 * organize the elements in the way described above. Swapping is done while comparing each element with the pivot.
 * The array is traversed within start and end index and each element is compared. If the element is smaller than
 * pivot, we swap the element with the current pivot_index(which is initialized with start index). Basically,
 * the pivot index is what we are returning, so at last, this index should have the pivot element. Therefore we
 * swap the last element, which we considered to be the pivot, and the pivot_index element before returning it.
 *
 * Analysis : --------------------------------------------------------------------------------------------------------
 *
 * 1. Not Stable : If we are sorting a pair with this algorithm, it is not guarenteed that it maintain their relative order.
 *                 Means, if we have a pair (2,5) before (2,3), then after sorting, it is not sure which one of (2,5),(2,3)
 *                 will occur first.
 *
 * 2. Time Complexity : O(nlogn) in average and best case and O(n^2) in worst case. Worst Case is when the array is already
 *                      sorted and the pivot is the last element.
 *
 * 3. Space Complexity : O(logn) in average and O(n) in worst case. But it does not uses any constant extra space.
 *
 *
 *
 * NOTE : INplace is the one which take *constant extra space*. Focus on the word EXTRA. We can say that Quick sort is an
 *        inplace algo because it doesnot uses any extra space, but it does used some space on recursive calls.
 *
 * @param arr
 * @param start
 * @param end
 * @return int
 */

int part(vector<int>&arr, int start, int end){
    int pivot = arr[end], pindex = start;
    for(int i = start; i<=end; i++){
        if(arr[i]<=pivot) swap(arr[i],arr[pindex]), pindex++;
    }
    swap(arr[pindex],arr[end]);
    return pindex;
}

void quick_sort(vector<int> &arr, int start, int end){
    if(end<=start) return;

    // This one line below improves the overall performance of this Quick sort algorithm. We are choosing a random element from the start
    // and end region and swapping it with the last element. This will put a random element at the end, which we are taking as our pivot. 
    swap(arr[start + rand() % (end - start + 1)], arr[end]);

    int pivot_index = part(arr,start,end);
    quick_sort(arr,start,pivot_index-1);
    quick_sort(arr,pivot_index+1,end);
}

int main(){
    int n; cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    quick_sort(arr,0,n-1);
    for(auto u : arr) cout<<u<<" ";
    cout<<"\n";
}