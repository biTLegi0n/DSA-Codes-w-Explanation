#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   Take 3 pointers X, Y and Z
                - Initialize them to point to the start of arrays A, B and C
                - Find min of X, Y and Z.
                - Compute max(X, Y, Z) - min(X, Y, Z).
                - If new result is less than current result, change it to the new result.
                - Increment the pointer of the array which contains the minimum.
            Note that we increment the pointer of the array which has the minimum, because our goal is to decrease the
            difference. Increasing the maximum pointer is definitely going to increase the difference. Increase the
            second maximum pointer can potentially increase the difference ( however, it certainly will not decrease the
            difference ).
 */

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int ans = INT_MAX;
    while(i<A.size() and j<B.size() and k<C.size()){
        int t1=abs(A[i]-B[j]), t2=abs(B[j]-C[k]), t3=abs(C[k]-A[i]);
        int temp = max(t1,max(t2,t3));
        ans = min(ans,temp);

        if(A[i]<=B[j] and A[i]<=C[k]) i++;
        else
        if(B[j]<=A[i] and B[j]<=C[k]) j++;
        else
        k++;
    }
    return ans;
}