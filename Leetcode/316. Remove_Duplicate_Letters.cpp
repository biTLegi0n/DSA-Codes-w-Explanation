#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This was a very good question. In this problem, we were asked to find a lexicographically smallest string with no
            character repeating. To do that, we thought of monotonic stack. As we know, monotonic stack maintains a increasing or
            decreasing order of elements or characters. For lexicographically, we can maintain a increasing order, but since in
            this problem, monotonicity is not our final goal. We have to finally tell a subsequence which has no character repeating
            and then we check its monotonicity. Thus, if at any point, we have a character that will not repeat after its current
            occurence, we include that in our final result.
            Its not necessary to use stack in this question. We can also solve this problem using a simple string, instead of stack
            We only need to take care of the fact that the overall nature of the string should be increasing and that the characters
            should not repeat. Its the same as maintaining a stack, we pop the last element here. The code for the same can be found
            below.

 */

// Using stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack <char> st;
        vector <int> freq(26,0), visited(26,0);
        for(auto u : s) freq[u-'a']++;
        for(int i = 0; i<s.size(); i++){
            freq[s[i]-'a']--;
            if(st.empty()) st.push(s[i]), visited[s[i]-'a'] = 1;
            else{
                if(!visited[s[i]-'a']){
                    while(!st.empty() and s[i]<st.top() and freq[st.top()-'a']>0)
                        visited[st.top()-'a']--, st.pop();
                    st.push(s[i]);
                    visited[s[i]-'a']++;
                }
            }
        }

        string res = "";
        while(!st.empty()) res.push_back(st.top()), st.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};

// Using string
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string st = "";
        vector <int> freq(26,0), visited(26,0);
        for(auto u : s) freq[u-'a']++;
        for(int i = 0; i<s.size(); i++){
            freq[s[i]-'a']--;
            if(st.empty()) st.push_back(s[i]), visited[s[i]-'a'] = 1;
            else{
                if(!visited[s[i]-'a']){
                    while(!st.empty() and s[i]<st.back() and freq[st.back()-'a']>0)
                        visited[st.back()-'a']--, st.pop_back();
                    st.push_back(s[i]);
                    visited[s[i]-'a']++;
                }
            }
        }

        return st;
    }
};