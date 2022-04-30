#include <bits/stdc++.h>
using namespace std;

/**
 * @brief One way is to do this with brute force, which takes O(N^2) but we can do better.
 *        We open the mod (| |) just as we used to do in maths in high school. So we open it with +- signs.
 *        there will be four cases, ie ++, +-, -+, --, from those four, we realise that -+,-- is actually -(+-,++)
 *        Thus we are reduced to only two cases primarily (as we can take mod of the remaining two to find the max.)
 *        therefore, we find maximum of these two[[max(arr[i]+i)-min(arr[i]+i) and max(i-arr[i])-min(i-arr[i])]]
 *
 * @param arr
 * @return int
 */

int maxArr(vector<int> &arr) {
    vector <int> sum(arr.size()), diff(arr.size());
    for(int i = 0; i<arr.size(); i++){
        sum[i] = arr[i]+i;
        diff[i] = -arr[i]+i;
    }
    int max_sum = INT_MIN, min_diff = INT_MAX,min_sum = INT_MAX,max_diff=INT_MIN;
    for(auto u : sum) max_sum = max(max_sum,u),min_sum = min(min_sum,u);
    for(auto u : diff) min_diff = min(min_diff,u),max_diff=max(max_diff,u);
    return max(abs(max_sum-min_sum),abs(max_diff-min_diff));
}
