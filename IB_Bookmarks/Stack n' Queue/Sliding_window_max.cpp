#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   This problem was really really good. I tried it many times on leetcode, but was never able to solve it.
            The mistakes i did :
              - At first, i thought this is a problem of sliding window and thus, i approached it in that direction. So i
                did the sliding window thing and whenever i removed the meaximum element, i ran a for loop to find the next
                maximum in that window which took the time complexity of worst case to O(N*K);
              - When i attempted it during IB, i was able to think for priority_queue but, i did make one mistake. That was that
                i removed the elements from the priority queue using if() condition, which only removed one element while insertion
                which gave me wrong answers and also i while removing, i checked for equality, which was not necessary because
                in priority queue, elements arrange as highest index at top, so, i mistakenly removed higer indices first due to
                equality. For ex, [7,3,4,5,7,1,2], 3.

            The right approach :
              - Well the first one is done below. Here, instead of checking equality, i compared the indices and if the top() is
                not a part of window, we remove it, else we push it in our answer. The complexity of this approach becomes
                O(nlogk) in average case, and O(nlogN) in worst case.
              - The second approach was to use Doubly linked list, or list. This method could be done in O(N). What we do is simple
                Its just like maintaing an increasing stack, here we maintain a decreasing list. Whenever we have a number,
                1. We first remove all the elements from the start of the list which are out of bounds of the window.
                2. Then we start from the end of the list, and remove all the elements which are smaller than the current element
                   thus maintaing the decreasing order of the list.
                3. We finally return the front of the list which is our answer.
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> res;
        priority_queue <pair<int,int>> q;
        int sum = 0;
        for(int i = 0; i<k; i++){
            q.push({nums[i],i});
        }
        res.push_back(q.top().first);
        int low=0, high=k;
        while(high<nums.size()){
            while(!q.empty() and q.top().second<=low) q.pop();

            q.push({nums[high],high});
            res.push_back(q.top().first);
            low++, high++;
        }
        return res;
    }
};