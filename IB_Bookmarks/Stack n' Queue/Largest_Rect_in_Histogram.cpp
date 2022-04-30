#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   This problem was the best problem in the whole section. At first, i was not able to think of anything in this.
            Then, i saw their hint that said, that it is certain that the largest rectangle will have atleast one of the
            Histogram in it. This is true, as one of the bar will completely lie inside the largest rectangle. Having that
            in mind, we can consider each of the histogram as height and find the largest rectangle possible from that height.
            Largest rectangle possible from any height is the height*(longest width). Talking about longest width, we know that
            on both sides(ie on left and right), untill we have heights which are greater than or equal to our current height,
            we can count them in the rectangle, since they will be a part of it. So, we move on both sides untill we have a
            height which is smaller than current height.
            Now, If we proceed with brute force, we would end up with O(n*n) but we can use stack to find the next smaller
            element in both sides. The concept is not new to me, but i was not able to think of it in this problem. So we
            basically find the next smaller element on both sides of a histogram and stored them in prefix and suffix arrays.

 */

class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        vector <int> prefix(A.size(),0), suffix(A.size(),A.size()-1);
        stack <pair<int,int>> st;
        // finding next smaller element
        for(int i = 0; i<A.size(); i++){
            if(st.empty()) st.push({A[i],i});
            else{
                while(!st.empty() and A[i]<st.top().first){
                    suffix[st.top().second] = i-1;
                    st.pop();
                }
                st.push({A[i],i});
            }
        }

        // finding previous smaller element
        while(!st.empty()) st.pop();
        for(int i = A.size()-1; i>=0; i--){
            if(st.empty()) st.push({A[i],i});
            else{
                while(!st.empty() and A[i]<st.top().first){
                    prefix[st.top().second] = i+1;
                    st.pop();
                }
                st.push({A[i],i});
            }
        }

        int ans = 0;
        for(int i = 0; i<A.size(); i++){
            ans = max(ans, (suffix[i]-prefix[i]+1)*A[i]);
        }
        return ans;
    }
};