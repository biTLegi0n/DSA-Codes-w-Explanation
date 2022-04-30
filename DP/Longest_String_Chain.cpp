#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This question was easy. I approached it in wrong direction. I made a tree connecting the edges when two string are
            valid(ie one is predecessor of another). But with that, the only issue that was a pain in the a$$ was the fact that
            the graph could be disconnected as well. IN that case, we had to run the bfs/dfs for every unvisited node which would
            give us TLE. So we need to think simpler. Now, we know that bc and bac are two valid strings and ans(bc) = 1+ans(bac)
            How so? ans(bac) will be the max len if we start from "bac". So, if we start from its predecssor, we know for sure that
            we will have 1 extra length. Thus we get the recurrence as fun(b) = 1+fun(its children). With this recurrence in mind
            and using some dp, we can find the answer as done in below code.

            [NOTE] we need to take every string as start point and then compute the maximum answer. Note that answer for every string
            will be calculated only once...

 */

class Solution {
public:
    map <pair<int,string>,int> mp;
    int longestStrChain(vector<string>& words) {
        mp.clear();
        sort(words.begin(),words.end(),comp);

        int ans=0;
        for(int i = 0; i<words.size(); i++){
            ans = max(ans,1+fun(i,words[i],words));
        }
        return ans;
    }
protected:
    static bool comp(string &a, string &b){
        if(a.size()<b.size()) return true;
        return false;
    }

    int fun(int idx, string &str, vector<string>&words){
        if(mp.find({idx,str})!=mp.end()) return mp[{idx,str}];
        int ans = 0;
        for(int i = idx+1; i<words.size(); i++){
            if(isvalid(str,words[i])){
                ans = max(ans,1+fun(i,words[i],words));
            }
        }
        return mp[{idx,str}] = ans;
    }

    bool isvalid(string &str1, string &str2){
        if(str1.size()>str2.size()) return isvalid(str2, str1);
        if(1+str1.size()!=str2.size()) return false;

        int count = 0, i = 0, j = 0;
        while(i<str1.size() and j<str2.size()){
            if(str1[i]!=str2[j]) count++, j++;
            else i++, j++;
        }

        if(count<=1) return true;
        return false;
    }
};