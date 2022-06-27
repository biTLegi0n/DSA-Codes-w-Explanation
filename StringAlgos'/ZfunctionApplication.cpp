#include<bits/stdc++.h>
using namespace std;

/**
 * You are given a string s. You can convert s to a palindrome by adding characters in front of it.

    Return the shortest palindrome you can find by performing this transformation.

    

    Example 1:

    Input: s = "aacecaaa"
    Output: "aaacecaaa"
    Example 2:

    Input: s = "abcd"
    Output: "dcbabcd"

    In order to solve this one, we take the reverse of the string, and append it at the back of the original string, and now, find its 
    z_function values. At whatever point, we get pi[i]+i==n, we return the answer. Why? Because, pi[i] will tell us what length of prefix is 
    repeated after this index, and if this length is enough to complete the string, we return. We can claim that first answer will be the best
    answer because there will be only one pi[i] and i that satisfies this condition. 
 */

class Solution {
public:
    string shortestPalindrome(string s) {
        vector <int> pi(2*(s.size()+1),0);
        string temp = s;
        reverse(temp.begin(),temp.end());
        string str = s+"#"+temp;
        return zfunction(str,pi,s.size())+s;
    }
protected:
    string zfunction(string &s, vector <int>&pi,int k){
        int n = s.size();
       
        for(int i = 1, l=0, r=  0; i<n; i++){
            if(i<=r)
                pi[i] = min(r-i+1,pi[i-l]);
            while(i+pi[i]<n and s[pi[i]]==s[i+pi[i]]) pi[i]++;
            if(i+pi[i]-1>r) 
                r = i+pi[i]-1, l=i;
            
            // This condition is for the answer, above code is for pi[]/z array
            if(i+pi[i]==n){
                return s.substr(k+1,k-pi[i]); 
            }
        }
        return s.substr(0,k);
    }
};