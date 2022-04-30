#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This question might not seem intuitive at first but its actually really easy. We need to make smallest subsequence
            possible. I recommend you to solve monotonic stack's problems first, like [739. Daily Temperatures].
            Monotonic stacks are used to find the next smaller or next greater element in an array. The concept is, we keep on
            pushing the elements in stack untill we are on an element which is smaller than stack's top and when we reach such
            a number, we keep on popping the stack till the point where it is either empty or its top is smaller than our current
            element.

            Now, coming back to this question, here we need to find the next smaller element in such a way that overall subsequence
            is minimum possible. So, we maintain a track of number of elements remaining in the array and number of positions to be
            filled. When we have number of elements remining in the array equal to number of positions to be filled, we do not have
            any choice among the elements and we have to take all the elements in the same order. In other case, where we have enough
            elements to choose from, we run monotonic stack to find the minimum element possible at current position. While doing the
            same, we maintain the track of remaining positions as well, ie if we are removing something from stack, we increase the
            number of remaining positions and when we are pushing into stack, we decrease. At last, we need to pop the extra elements
            from our stack. Since it could have more elements than required. Thus we pop untill its size is equal to k.
            For ex. in case  nums = [2,4,3,3,5,4,9,6], k = 4, stack at last will be [6,4,3,3,2] whereas we only require 4 elements
            thus we remove the top elements which are greater than other elements in stack(because stack only stores monotonically).

 */

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int rem = k, count = 0, n = nums.size();
        stack <int> st;

        for(int i = 0; i<n; i++){
            if(st.empty()) st.push(nums[i]);
            else{
                // Count stores the number of elements present after current position
                count = n-i;
                // We will pop the stack untill the top is greater than current element and remaining elements are smaller than k
                while(!st.empty() and st.top()>nums[i] and count>=rem and rem<=k) st.pop(), rem++;
                st.push(nums[i]);
                rem--;
            }
        }
        vector <int> res;
        // Popping the extra elements that are greater than others.
        while(st.size()>k) st.pop();
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
