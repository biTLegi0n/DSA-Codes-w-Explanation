#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   This problem has many ways to solve. One it to count the number of ones and zeros and then, keep on adding zeros and then ones
 *          and the remaining will be 2s. Now, another way is that we maintain a pointer k, which pushes all the 0s to the left and 2s to
 *          the right. if(A[k] is 0), we swap it to the left, and increase k and i, if it is 2, we swap it to the right, but here, we dont
 *          increase k, because, there could be a case, where 2 may be swapped with 1. so for that, we just decrease j. and in case of 1,
 *          we increase k.
 */

void sortColors(vector<int> &A) {
    int i = 0, j = A.size()-1,k=0;
    while(k<=j){
        if(A[k]==0) swap(A[k],A[i]), k++,i++;
        else
        if(A[k]==2) swap(A[k],A[j]), j--;
        else
        k++;
    }
}
