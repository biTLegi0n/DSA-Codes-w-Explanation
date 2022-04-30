#include <bits/stdc++.h>
using namespace std;
/**
  @brief    In this problem, We can go for dp which take O(n^2) time while greedy here takes O(n) time only. In greedy,
            we maintain a currjumps variable which is initialized to first element, maxjumps which is also initialised to
            first element, and a jumps variable which contains the number of jumps we have to take. Now, whenever our curr
            jump reaches the end of its ladder, we have to make a jump. We move like, when we have a maximum jump size, we
            make our mind to use that jump to get off the current ladder. Means, if our array is [2,5,.....10.....],
            then in first itr, we go to 5, and make our mind to make the next jump of 5, untill we get a bigger jump/element.
            Now when 2 steps will end, we will make a jump of 5 from current location(i+arr[i]). Similiarly, when we will go
            to 10, which is the maximum, then we update the max jump. Whenever our current jump ends, we must have updated our
            max jump, thus, we set curr to that and increase the value of jump by 1. dont visualise the process, see whats'
            going inside. wE are not making a jump from the last point of a ladder in real, no, we are making a jump at the
            biggest element of that ladder and then from there to next biggest element, and counting these jumps.



This one is pretty straight forward and the one that gives TLE
    int Solution::jump(vector<int> &arr) {
        int n = arr.size();
        vector <long long> dp(n,INT_MAX);

        dp[0] = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<=arr[i] and i+j<n; j++){
                dp[i+j] = min(dp[i+j],1+dp[i]);
            }
        }
        if(dp[n-1]>=INT_MAX) return -1;
        return dp[n-1];
    }
*/
// This codde runs in linear time
int jump(vector<int> &arr) {
    int n = arr.size();

    if(n<2) return 0;

    int curr = arr[0], maxjump = arr[0];
    int jumps = 1;
    for(int i = 0; i<n-1; i++){
        if(i+arr[i]>maxjump) maxjump = i+arr[i];

        if(curr == i) jumps++, curr = maxjump;
    }

    if(curr>=n-1) return jumps;
    return -1;
}
