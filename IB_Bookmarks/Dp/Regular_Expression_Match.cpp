#include <bits/stdc++.h>
using namespace std;

/**
  @brief     Approach : we as usual, makes two choices but on one condition here. If pattern[j] == '*', then only we make our choices, because
               this '*' could replace one character as well as a series of characters. if we have a '?', then we have no choice at all.
               We just replace it and move ahead. Also, we need to check one thing that if the current characters of both str and pattern
               mismatch and it is not '?', then the answer will be false. So we directly return false from there.
               -> The trick is in its base cases also. We see that if both the string have been traversed, then we return true.
                  if only pattern has been traversed fully, then we can't convert the pattern string in str, thus return false.
                  if only str has been traversed, then we check if we have only '*' in the end of pattern, we can replace all the '*'
                  by NULL and can still have the str, but if we have anything else than that, we return false.

 */

bool fun(int i, int j, const string &str1,const string &str2,unordered_map <string,bool>&mp){
    string key = to_string(i)+'%'+to_string(j);

    if(j>=str2.size()){
        if(i>=str1.size()) return true;
        return false;
    }
    if(i>=str1.size()) {
        while(j<str2.size()){
            if(str2[j]=='*') j++;
            else break;
        }
        if(j>=str2.size()) return true;
        return false;
    }
    if(mp.find(key)!=mp.end()) return mp[key];

    if(str1[i]==str2[j] or str2[j]=='?') return mp[key] = fun(i+1,j+1,str1,str2,mp);
    else
    if(str2[j]=='*') return mp[key] = fun(i+1,j,str1,str2,mp) or fun(i,j+1,str1,str2,mp);
    return false;
}

int isMatch(const string A, const string B) {
    int count = 0;
    for(auto u : B) if(u!='*') count++;
    if(count>A.size()) return false;

    unordered_map <string,bool> mp;

    return fun(0,0,A,B,mp);
}