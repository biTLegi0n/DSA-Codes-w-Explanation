/**
 * @file Longest_Valid_Parenthesis(HARD).cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-10-01
 *
 * @copyright Copyright (c) 2021
 *
 * Problem :
 * 32. Longest Valid Parentheses
    Hard
    Given a string containing just the characters '(' and ')', find the length of the longest valid
    (well-formed) parentheses substring.

    Example 1:

    Input: s = "(()"
    Output: 2
    Explanation: The longest valid parentheses substring is "()".

    Example 2:

    Input: s = ")()())"
    Output: 4
    Explanation: The longest valid parentheses substring is "()()".

    Example 3:

    Input: s = ""
    Output: 0

 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
	In  order to solve this one, we will not push '(' or ')' in stack, instead, we would push indices of opening
	braces and whenever we encounter any closing, we make the recent opening valid and mark this
	closing as valid as well. Remember, stack only take opening. After doing this, we will have an array of 0s and 1s
	and that will reduce this problem to counting consecutive 1s.
    */
    int longestValidParentheses(string s) {
        stack <int> st; // it would hold the indices which will give us the longest length ;)
        vector <int> arr(s.size(),0);
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty()){
                    arr[st.top()] = 1;
                    arr[i] = 1;
                    st.pop();
                }
            }
        }
        for(auto u : arr) cout<<u<<" ";
        cout<<"\n";
        int ans=0,count=0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]==0) count=0;
            else{
                count++;
                ans = max(ans,count);
            }
        }
        return ans;
    }
};

int main(){
    Solution ob;
    string str;
    cin>>str;
    cout<<ob.longestValidParentheses(str)<<"\n";
}