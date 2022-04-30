#include <bits/stdc++.h>
using namespace std;

/**
 @brief     This question is easy peasy lemon cheesy. You just need to have some knowledge about monotonic stack. In case you
            do not know what monotonic stack is, it is a stack that maintains an increasing or decreasing order in its elements
            For better explanation of monotonic stack, watch https://www.youtube.com/watch?v=sDKpIO2HGq0
            Once you know what monotonic stack is, this question is just its implementation. Just start from the end of the array
            and find the next greater element for each element. This way, you end up having the count of all people greater than
            current element.

 */

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector <int> res(n);
        stack <pair<int,int>> st;

        for(int i = n-1; i>=0; i--){
            if(st.empty()) st.push({heights[i],i});
            else{
                // You can see that here i do res[i]++ because we need to store the count of people that current element can see
                // and since stack contains elements in decreasing order, ie bottom is max and top is min, therefore if current
                // is greater than x elements, that clearly means current person can see x elements.
                while(!st.empty() and st.top().first<heights[i]) res[i]++, st.pop();
                // If stack is not empty, then that means that we have an element which is greater than current element thus we
                // add 1 to our result.
                if(!st.empty()) res[i]++;
                st.push({heights[i],i});
            }
        }
        return res;
    }
};