#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This is yet another simplest question that i couldn't do! In this, we need to find a pair such that its
            a+b-(distance bw them) is max. To achieve that, we maintain a curr variable, which stores the maximum
            element so far and in each iteration, we are reducing this maximum element by 1. Whether its the previous
            element which remained max or a new element became max, we keep reducing it. Then, in each iteration, we also
            keep checking the answer by adding the current element to max_so_Far.

 */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, curr = 0;
        for(int i = 0; i<values.size(); i++){
            ans = max(ans,curr+values[i]);
            curr = max(curr,values[i]) - 1;
        }
        return ans;
    }
};