#include <bits/stdc++.h>
using namespace std;

/**
 * @brief For more detailed explanation, refer to tech dose video.
 *
 * ----> The whole idea revolves around the fact that to find the next greater permutation, we need to start from the
 *       elements having less weights, that is from end elements. Just like we do with numbers.
 *
 * Basically in this problem, we build the intuition just like we would do with a number. Suppose we had a number 25341
 * Now, the next greater number would've been 25413. What we did here, we swapped the last peak, ie, we saw that while
 * traversing the number from back, we have 4>3, we stop here, and declare it a peak, now, shift the peak to left to make
 * it a larger number, and after that, we will have 25431. Although it is greater than 25341, but it is not just greater.
 * A just greater number is 25413, ie, after swapping, we sorted all the remainings. Now, we know that sorting gives the
 * minimum number possible, ie, 12345 is the minimum possible, therefore, by sorting the remainings, we ensure to have the
 * minimum possible permutation.
 * Now there is one more catch, ie, if we had something like 23541, then we observe that first peak is with __35_ but we would
 * not swap 3 and 5, instead, we will look in the right hand side, for a number which is greater than 3 but less than current
 * peak 5. We do this because to find the next greater permutation, we need to swap the number which is just greater than our
 * local minima. So in the below code, you can see that once we find the peak, we look for a number which is just graeter than
 * our local minima and we keep on changing the peak....in order to find the just greater number.
 *
 * @param arr
 * @return vector<int>
 */

vector<int> nextPermutation(vector<int> &arr) {
    int peak = -1, index=-1;
    // mOve the peak having least weigtage and sort the remaining subarray because that gives us the smallert possible
    for(int i = arr.size()-1; i>0; i--){
        if(arr[i]>arr[i-1]){
            peak = i;
            index = i-1;
            break;
        }
    }
    if(peak == -1 or index == -1){
        // already sorted in descending order, therefore no nextPermutation
        reverse(arr.begin(), arr.end());
        return arr;
    }
    else{
        for(int i = peak; i<arr.size(); i++){
            if(arr[i]<arr[peak] and arr[i]>arr[index])
                peak = i;
        }

        swap(arr[peak],arr[index]);
        sort(arr.begin()+index+1,arr.end());
        return arr;
    }
}
