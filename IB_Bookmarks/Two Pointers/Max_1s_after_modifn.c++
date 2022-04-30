#include<bits/stdc++.h>
using namespace std;

/**
 * @brief       In this question also, i made a mistake of hashing the values. WHY? WHY DO I DO THAT?
 *              well, this was pretty simple, simpler than other problems. We just need to maintain a subarry having
 *              atmost B number of 0s. Also, we need to take care of the low and high at the same time.
 *              Like, for ex, 0 1 0 1 0 0 0 1 1, in this example, in one case, when low = 1, and high = 5, at that time,
 *              when we increment high to high+1, we increase the counter, and counter becomes > B, so we do low++ and
 *              count--! No, dont do counter-- untill A[low]==0! because in this case, when we do count--, we are not actually
 *              reducing the count of zeros, so we will have 4 zeros in that subarray with the count of 3.
 *
 * @param A
 * @param B
 * @return int
 */

int solve(vector<int> &A, int B) {
    int low = 0, high = 0, count = 0,ans=0;
    while(low<A.size() and high<A.size()){
        if(A[high]==0) count++;
        if(count>B){
            if(A[low]==0) count--;
            low++;
        }
        else
            ans = max(ans,high-low+1);

        high++;
    }
    return ans;
}
