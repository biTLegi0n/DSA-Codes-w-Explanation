#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this problem, * replicates its previous character and not any character. This is the only challenge. So, we
            see it like, if the next character is *, then we make the choices regarding the current character. If the current
            character is equal to str1[i], then we can make choices to replicate it or omit it, else we have to omit it. Because
            this character is not equal to the current character of index i. This is the first condition, now in next, we check
            if(two characters are equal or if str2[j]=='.'), in both cases, we move one one pointer in each string. In neither
            of these cases, we return false.

 */

unordered_map <string,bool> mp;
bool fun(int i, int j, const string &str1, const string &str2){
    if(j>=str2.size()){
        if(i>=str1.size()) return true;
        return false;
    }
    if(i>=str1.size()){
        while(j<str2.size()){
            if(str2[j+1]=='*') j+=2;
            else break;
        }
        if(j>=str2.size()) return true;
        return false;
    }
    string key = to_string(i)+'$'+to_string(j);

    if(mp.find(key)!=mp.end()) return mp[key];

    if(j<str2.size()-1 and str2[j+1]=='*') {
        if(str1[i]==str2[j] or str2[j]=='.')
            return mp[key] = fun(i,j+2,str1,str2) or fun(i+1,j,str1,str2);
        else
            return mp[key] = fun(i,j+2,str1,str2);
    }
    else
    if(str1[i]==str2[j] or str2[j]=='.') return mp[key] = fun(i+1,j+1,str1,str2);

    return mp[key] = false;
}
int isMatch(const string A, const string B) {
    mp.clear();
    return fun(0,0,A,B);
}
