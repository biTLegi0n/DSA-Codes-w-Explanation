/**
 * @file Partition_K_equal_sum_subsets.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-12
 * 
 * @copyright Copyright (c) 2021
 * 
698. Partition to K Equal Sum Subsets
Medium

Given an integer array nums and an integer k, return true if it is possible to divide this array 
into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for(auto u : nums)
            sum += u;
        
        if(sum%k != 0)
            return false;
        
        sum = sum/k;
        vector <bool> visited(nums.size());
        
        if(partition(nums, visited, 0, 0, sum, k))
            return true;
        return false;
    }
    
private:
    bool partition(vector <int> &nums, vector <bool>&visited, int ind, int curr, int target, int k){
        //base case1
        if(k == 1)
            return true;
        //base case2
        if(curr == target)
            return partition(nums, visited, 0, 0, target, k-1);
        //base case3
        if(curr > target)
            return false;
        
        // Starting from the current index, we check for each unvisited element if it could be a part of 
        // subset or not
        for(int i = ind; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                if(partition(nums, visited, i+1, curr+nums[i], target, k))  // Recursion
                    return true;
                visited[i] = false;     // Backtracking
            }
        }
        return false;
    }
};