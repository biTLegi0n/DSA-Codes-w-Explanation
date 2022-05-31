#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This type of problem where we need to check the occurances of some characters and form our answer when a particular
            range satisfies we go with the following approach. We maintain a counter variable and use it to satisfy the range
            answer and usually, when it becomes zero, we push the answer.
            This question can be found in leetcode.
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> freq(26,0);
        for(auto u : s)
            freq[u-'a']++;

        vector <int> curr(26,0);
        int count = 0, len=0;
        vector <int> res;
        for(int i=0; i<s.size(); i++){
            len++;
            curr[s[i]-'a']++;

            if(curr[s[i]-'a']==1)
                count++;
            if(curr[s[i]-'a']==freq[s[i]-'a'])
                count--;

            if(count==0){
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};