/**
 * @file Longest_Consecutive_Sequence.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-11-15
 *
 * @copyright Copyright (c) 2021
 *
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.



    Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9

 */
#include <bits/stdc++.h>
using namespace std;

/*
    To fulfill the requirements of time complexity, we maintain a unordered_map/set in which insertion time is O(1) and also find operations
    is fast. In that map, we mark the entries of each number once. Then, we find the minimal element. Means, we find a element which is less
    then all other elements which will be a part of the consecutive sequence starting from this number. Doing so will only reduce to run the
    second loop the same number of times as there are these minimal elements. also, we go for minimal only because thats where it begins. Since
    there is no other smaller element. so we can start counting the length.....
*/

class Solution {
public:
    //Below solution was not my intuition, I watched striver
    // iT is O(3N)
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map <int,int> mp;
        for(int i = 0; i<nums.size(); i++)
            mp[nums[i]]++;
        // What we do is that at each number we check if it is minimal or not. If it is minimal, we then keep moving 1 step ahead,
        // till we can. for more watch https://www.youtube.com/watch?v=qgizvmgeyUM

        int ans = INT_MIN, count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(nums[i]-1)==mp.end()){
                int k = nums[i];
                count=0;
                while(1){
                    if(mp.find(k)==mp.end()) break;
                    k++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};