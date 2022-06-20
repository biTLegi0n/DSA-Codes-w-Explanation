#include <bits/stdc++.h>
using namespace std;

/**
  @brief This was a really good question. It can be solved using brute force but even its brute force would be difficult.
        As we have to find two numbers, one in left, another in right and with the condition that k>j and i>k>j. To achieve this,
        we will have to run three nested loops taking the complexity to O(N^3)
        Instead, a little knowledge of stack, more specifically monotonic stack, would help a lot in this problem.
        In case you don't know what a monotonic stack is, please watch this video. He has explained it beautifully.
        To practice a few questions, please solve this

        After you have a sufficient amount of knowlede of monotonic stacks, you can have some intuition of this problem too.
        Lets first see what this question demands. It want us to find three numbers, let's name them i, j, k, such thatj>k>i.
        To achieve that, we can maintain a monotonically decreasing stack.
        Why decreasing? Well, if we will have a decreasing stack, we would have two numbers,j and k, and our task will reduce
        to finding an i such that i<k<j, and its in the left of j. Our stack will always ensure that j>k and k is in the right
        of j.
        To find a suitable i, what we can do is we can have a prefix array, that stores the minimum element on the left so far.
        Now having that data with us, in each iteration, we can now check if our stack has some elements, and if it does,
        we check if the prefix (minimum_so_far) element is smaller than stack top, ie k. If we get that, we return true.


 */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <pair<int,int>> st;
        vector<int> prefix(nums.size(), INT_MAX);

        int mini = INT_MAX;

        for(int i = 0; i<nums.size(); i++){
            prefix[i] = mini;
            mini = min(mini, nums[i]);
        }

        for(int i = 0; i<nums.size(); i++){
            if(st.empty()) st.push({nums[i],i});
            else{
                while(!st.empty() and nums[i]>=st.top().first) st.pop();

                if(!st.empty() and prefix[st.top().second]<nums[i]) return true;

                st.push({nums[i],i});
            }
        }
        return false;
    }
};