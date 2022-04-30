#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Well, at first i tried solving this problem using the conecpt that i learned while doing dp, palindrome partition
            count, but, here, we dont need the count, we need to find the palindromes. Thus, we cannot go with that, because,
            then, we will not have any method to discard the substrings which are not palindromes. Thus, the following appraoch
            was very nice and straightforward

  @a ppraoch:
            We check the right substring, iff our left substring is a palindrom. In that case, we ensure that atleast on of the
            partition will be the part of our temp vector. Doing so, removes the headache of storing substrings and discarding
            them we were having in the above discussed method. Now, we store the left in temp, iff it is palindrome and check for
            the right one. And, when we reach at the end of the string, ie, there exists no right substring and left is palindrome,
            we return. For ex, in aabb, when we reach "aabb|", and we partition at the very end, we return true. Note that since at
            that stage, left has already been pushed.

 */

class Solution {
public:
    bool ispalin(string str){
        int i = 0, j = str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++,j--;
        }
        return true;
    }

    bool fun(string str, vector<string>&temp, set<vector<string>>&res){
        if(str.empty()) return true;

        for(int i = 0; i<str.size(); i++){
            string left = str.substr(0,i+1), right = str.substr(i+1,str.size()-i);
            if(ispalin(left)){
                temp.push_back(left);
                if(fun(right,temp,res))
                    res.insert(temp);
                temp.pop_back();
            }
        }
        return false;
    }

    vector<vector<string>> partition(string s) {
        vector <string> temp;
        vector<vector<string>> ans;
        set <vector<string>> res;
        fun(s,temp,res);
        for(auto u : res) ans.push_back(u);
        return ans;
    }
};