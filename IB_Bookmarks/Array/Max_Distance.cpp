#include <bits/stdc++.h>
using namespace std;

/**
 * @brief So basically no improvement in brute force can do this question. Here we did it in O(n+nlogn).
 *        What we are doing is not my intuition. We make a vector with indices and values, as {value,index};
 *        Sort this vector, and after sorting, we find a minimum index till now, and because the array is sorted,
 *        therefore, upcoming elements will be greater than the element whose minimum index we have, thus the
 *        condition is already satisfied, we only need to compare the max diff (j-i).
 *        The thing is that we are on an element in the sorted vector, we see if the current index, is minimum
 *        (we see minimum because for j-i to be maximum, i has to be minimum, i mean, not necessarily but it has to be less)
 *        and so while checking for minimum, we keep on checking ans...
 *
 * @param A
 * @return int
 */

int maximumGap(const vector<int> &A) {
    vector <pair<int,int>> arr;
    for(int i = 0; i<A.size(); i++) arr.push_back({A[i],i});
    sort(arr.begin(), arr.end());

    int mini = arr[0].second;
    int ans = INT_MIN;
    for(int i = 1; i<arr.size(); i++){
        ans = max(ans,arr[i].second-mini);
        mini = min(mini,arr[i].second);
    }
    if(ans<0) return 0;
    return ans;
}
