#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This problem is a standard dp problem, but it can be solved in a very efficient way, by just using some facts.
            We can only keep track of how far we can reach, and simply solve it that way. You can refer the code below. We are
            checking how far we can reach, and then, we just keep that record and at last check if we could reach the end or not.

 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0, i=0;
        for(; i<nums.size() and i<=pos;i++){
            pos = max(pos,i+nums[i]);
        }
        if(i>=nums.size()) return true;;
        return false;
    }
};

// O(N^2) complexity DP solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector <bool> dp(nums.size()+1,false);
        dp[n-1] = true;
        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<=nums[i] and j+i<n; j++){
                if(dp[i+j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

// When we have to count the number of steps
int jump(vector<int>& nums, int pos = 0) {
	if(pos >= nums.size() - 1) return 0;
	int minJumps = 10001;  // initialising to max possible jumps + 1
	for(int j = 1; j <= nums[pos]; j++)  // explore all possible jump sizes from current position
		minJumps = min(minJumps, 1 + jump(nums, pos + j));
	return minJumps;
}