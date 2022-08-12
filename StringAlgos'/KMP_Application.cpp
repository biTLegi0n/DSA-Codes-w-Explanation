/*
686 Repeated String Match
Medium

1659

912

Add to List

Share
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. 
If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
*/
#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This question took days. Literally, days.... I managed to do this with the help of a blog. Well, what the concept of KMP
            says is that we dont have to restart from the first character everytime we get a mismatch, rather we start from the character 
            from where we started finding mismatch. Because, while maintaing prefix array in kmp, we store the length of the longest prefix
            which is also a suffix, so current index denotes the end of suffix, and thus, if at the end, we find this mismatch, then using 
            KMP, we jump at prefix[curr_idx] because character before this index, and upto a certain index, are same as that of current suffix. 

            This is the use of KMP. I know it could be a little hard to grasp all this just by reading. therfore, i humbly request you to take 
            your pen and paper and simulate this example.

            a = "aaabaab"
            b = "baabaaabaaba"

            The answer is : 3
            
            so, when you do simulate it, you will make KMP array of b. 
            that would look like 
            ind[] : 0 1 2 3 4 5 6 7 8 9 10 11
            str   : b a a b a a a b a a b  a
            kmp[] : 0 0 0 1 2 3 0 1 2 3 4  5  

            So, we see that if we get a mismatch at last character of str, then we wont reset the index to the start of the string, NO. Rather, 
            we will set it at index 5, because, before it, the string has already been checked for similiarity. 

            Next, we need to note the while loop. Just see that what this while loop does is, it sets a particular index in string 'a', and check if
            starting from this index, i can get the whole string. If i can get this string, ie, this is the index from where the string will start and
            will repeat, else we move to the next index.
            One thing is that, the first if condition, in the while loop, it basically increments j, and not i, so as to check if all the upcoming
            characters can be traced by starting from current index. 

            Thats all. Thats how we code using KMP. 
 */

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // Checking if there is any character of 'a' that is not present in string 'b'. If there is, then we directly return false;
        unordered_map <char,int> mp;
        for(auto u : a) mp[u]++;
        for(auto u : b) if(mp[u]==0) return -1;
        
        // Else, we find the KMP of string b, so that, when we find a mismatching character, we move backwards only till we have this mismatch.
        vector <int> pi = kmp(b);
        
        int i=0,j=0;
        while(i<a.size()){
            if(j<b.size() and a[(i+j)%a.size()]==b[j]){
                j++;
                continue;
            }
            if(j==b.size()) return ((i+j-1)/a.size())+1;
            j = pi[j];
            i++;
        }
        return -1;
    }
protected:
    vector <int> kmp(string str){
        vector <int> pi(str.size()+1,0);
        for(int i = 1; i<str.size(); i++){
            int j = pi[i-1];
            while(j!=0 and str[i]!=str[j]) j = pi[j-1];
            if(str[i]==str[j]) j++;
            pi[i] = j;
        }
        return pi;
    }
};