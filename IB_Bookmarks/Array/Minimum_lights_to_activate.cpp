#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 *
 * In this problem, i thought of making choices using DP but that was not possible as we have to change
 * the visited/lighted values after each choice. This problem is approached with greedy methods.
 * We will find a window which is B-1 bulbs on left and B-1 on right. Then in that window, we will select
 * the rightmost '1' in that window so that we can cover maximum area in front. We take the left and
 * accordingly. If we do not find any 1 in the window of right to left, we can directly return -1, else
 * we count each one and finally return the count.
 *
 * @param arr
 * @param b
 * @return int
 */

int solve(vector<int> &arr, int b) {
    int n = arr.size();
    int i = 0, count=0;
    while(i<n){
        int left = max(0,i-b+1);
        int right = min(n-1,i+b-1);
        bool flag = false;
        while(right>=left){
            if(arr[right]==1){
                flag = true;
                break;
            }
            right--;
        }

        if(!flag) return -1;

        i = right+b;
        count++;
    }
    return count;
}
