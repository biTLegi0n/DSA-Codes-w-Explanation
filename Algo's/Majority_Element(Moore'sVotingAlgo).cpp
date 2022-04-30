/**
 * @file Majority_Element.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-08-22
 *
 * @copyright Copyright (c) 2021
 * Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



    Example 1:

    Input: nums = [3,2,3]
    Output: 3

    Example 2:

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

    Follow-up: Could you solve the problem in linear time and in O(1) space?
 */
#include <bits/stdc++.h>
using namespace std;

// An interesting question link : https://www.interviewbit.com/old/problems/n3-repeat-number/

// Its solution can be found in IB/ARRAY section
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // This is Moore's Voting algorithm

        int count = 1, major = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != major){
                count--;
            }
            else
                count++;
            if(count == 0){
                major = nums[i];
                count++;
            }
        }
        return major;
    }
};