#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   Following question is a good variation of Binary Seach on Answer. Here, we do not return when we satisfy a particular condition,
 *          we return when the condition low>high happens, ie when we run out of moves. Why so? Well there are reasons, explained below in
 *          between the code. Basically, this is to avoid returning an element which does not exists in the matrix. So, by doing this, we
 *          only return the elements which does exists in the matrix. So we run binary search on the range [1,INT_MAX] and in each binary
 *          search call, we count the number of elements which are smaller than that particular number. We do that for all the rows of the
 *          matrix and we use Binary Search Only!
 *
 * @param arr
 * @param n
 * @return int
 */

int count_smaller(vector<vector <int>>&arr, int n){
    int res=0;
    for(int i = 0; i<arr.size(); i++){
        int low = 0, high = arr[i].size()-1;
        int count = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[i][mid]<=n){
                count = mid+1;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        res +=count;
    }
    return res;
}

int findMedian(vector<vector<int> > &mat) {
    int m = mat.size(), n = mat[0].size();
    int low = 1, high = INT_MAX, req = m*n/2;
    int res = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        int smaller = count_smaller(mat,mid);
        /*
        This below portion was giving me the wrong answers. Why? Because, due to this, sometimes my function was returning a number
        that does not exists in the matrix! How can that be? Well, if i have a matrix in which the mid is someting like x and there are
        req number of elements which are smaller than this, then the below code snippet would've return that mid. But that mid does not
        exists in the matrix. Now, when i have such a mid, then by the else condition (smaller<=req), i will update low to mid+1, checking
        for a number that gives me mid, which has number of elements <= required elements. This case also handles the cases where the
        median is repeated. For example, if we have a final array as [1,2,3,4,6,6,6,6,7], here we know that median will be 6, but the below
        code snippet might've returned 5. But now, even when we have 5, we will run the while loop till the case when low>high!!
        At this point, we will be standing at our median. This is not normal in Binary Search but this is a good variation.
        */
        // if(smaller == req+1){
        //     return mid;
        // }
        // else

        if(smaller>req)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}
