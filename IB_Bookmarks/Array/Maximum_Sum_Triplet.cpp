#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * Here, in this problem, if we go with Kinda brute force, that will cost us O(N^3) to fix two numbers and find the third one
 * Doing something better can bring that to O(n^2). That is with Considering every element as middle element and then searching the
 * eligible element on the left and right. But that too is not the optimal approach. The best way is :
 * We make a suffix array, that actually stores the max element in the right from a position 'i'. Now, since the third element has
 * to be greater than remaining two, thus, Suffix array will work for the third element. Then we fix the middle element, and in each
 * iteration, we push the current element in set, and with the STL find(), we find the element which is smaller than the current element
 * or previous element of the current element since that will be the greatest on LHS. In this way, we will manage to solve the problem in
 * O(nlogn). O(n) for considering element middle and for finding suffix, and logn to find the largest element smaller than current.
 *
 * @param arr
 * @param b
 * @return int
 */

int solve(vector<int> &arr) {
    vector <int> suffix(arr.size());

    int maxi = INT_MIN;
    for(int i = arr.size()-1; i>=0; i--){
        suffix[i] = maxi;
        maxi = max(maxi,arr[i]);
    }

    set <int> s;
    int ans = 0;
    s.insert(arr[0]);
    for(int i = 1; i<arr.size()-1; i++){
        if(arr[i]>suffix[i]) continue;

        s.insert(arr[i]);

        auto it = s.find(arr[i]);
        if(it!=s.begin()) ans = max(ans,(*(--it)+arr[i]+suffix[i]));
    }
    return ans;
}
