/**
 * @file Generating_Subsets_of_array.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-07-11
 *
 * @copyright Copyright (c) 2021
 *
As the test cases are also low, therefore, it is a good application of Backtracking.
We will go through all the possible subsequences, push them in any set or use any other technique to remove the duplicates.
One thing to note is that the for loop in helper function is important because it helps us to generate all the subsequences we need.
As if we dont include this, we would be stuck. This for loop loops through all the elements of the array. :)
Problem Link : https://leetcode.com/problems/subsets/
More help : https://www.youtube.com/watch?v=RIn3gOkbhQE
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set <vector <int>> res;
        vector <int> temp;
        helper(res, temp, nums, 0);

        vector <vector <int>> ans;
        for(auto u : res)
            ans.push_back(u);

        return ans;
    }

private :

    void helper(set <vector <int>>&res, vector <int>&temp, vector <int>&nums, int index){
        res.insert(temp);

        // This for loop is necessary for generating subseq as if we dont use this, then we will have sequences starting from 1 only,
        // and not be able to make choices of whether to leave current elem or include it!
        for(int i = index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(res, temp, nums, i+1);
            temp.pop_back();
        }

        return;
    }
};