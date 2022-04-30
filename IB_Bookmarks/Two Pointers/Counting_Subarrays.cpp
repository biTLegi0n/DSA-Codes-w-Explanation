#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   Since in this question, we are asked to find subarrays with sum <= B, therefore, using map is not a good idea!
            because in that, we wont be able to find out the number of subarrays having sum <B, we can only find sum==B
            Now, since map is not a option, and we are asked of subarrays, we can go with two pointers maintaining a sliding
            window whose sum < B. Now, each time we have a sum >= B, we move the left pointer to the right, and in each iteration,
            we add the number of subsets which is {(high-low)+1}(it counts all, ie, even if a number is less then B, it says 0-0+1)

 * @param A
 * @param B
 * @return int
 */

int solve(vector<int> &A, int B) {
    int low=0,high=0,sum=0,count=0;
    while(low<A.size() and high<A.size()){
        sum += A[high];

        while(sum>=B)
            sum -= A[low], low++;

        // this means that subarrays that are ending at high! Now, they start from low, thatswhy, we do, high-low+[1]-> 1 for ig high itself
        count += (high-low+1);
        high++;
    }
    return count;
}
