#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   I tried this problem with 2 other approaches, one where i removed each character, and then checked if the remaining string is a
 *          palindrome of not. Other, where i used longest palindromic subsequnece concept of DP. Now both of them had a complexity of O(n^2)
 *          The method below is implemented in o(n/2).
 *          Its base concept is that whenever we have a conflicting pair of mismatching indices from front and back end, we increase the counter
 *          and if at the end, we have a counter>1, we return false.
 *          Now this is not my intuition, but this was a great idea. I mean, we just count the number of conflicting pairs of indices.
 *
 * @param str
 * @return int
 */

int solve(string str) {
    int i = 0, j=str.size()-1,count=0;
    while(i<=j){
        if(str[i]==str[j]) i++,j--;
        else
        if(str[i+1]==str[j]) count++,i++;
        else
        if(str[i]==str[j-1]) count++,j--;
        else
        return 0;
    }
    if(count<=1) return 1;
    return 0;
}
