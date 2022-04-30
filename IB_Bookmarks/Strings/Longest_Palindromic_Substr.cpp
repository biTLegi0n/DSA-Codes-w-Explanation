#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   This problem was approached in various ways. I was asked LPS, so i did use DP's LPS concept. But that failed on cases like
 *          S = “abacdfgdcaba”  ,    S’ = “abacdgfdcaba”
            The longest common substring between S and S’ is “abacd”. Clearly, this is not a valid palindrome. So in cases where we have
            a reverse copy of a substring in the string, in such cases, that approach fails. Also it take extra O(n^2).

            Now a second method could have been by using memoization. As, if the characters i and j match, then we have to check if
            substring(i+1,j-1) us a palindrome or not. Now this could be achieved by memoization.

            Afterall, we have a third approach, which is simple and clean. Here, we use O(1) extra space and O(n^2) complexity.
            We run two loops here. One is to find the palindromes of even length where we initialize the start and end as i, i+1
            and another is for odd length palindromes, where we initialize the start and end at the same index. Now, in this too,
            if at each comparision, we find the substring, and then compare to find the longest, that would be costly, therefore,
            we just find the length, the start and the end index of the longest palindrome. After that, we can find the palindrome at
            the end. Till the characters of the i,j are matching, we will consider that to be palindrome and we will keep on updating the
            lengths, and once they mismatch, we break the loop for that particular index.
 */

string longestPalindrome(string A) {
    string lps = "";
    int start = 0, end = 0, len = 0;
    for(int k = 0; k<A.size()-1; k++){
        int i = k, j = k+1;
        while(i>=0 and j<A.size()){
            if(A[i]==A[j]){
                // if(A.substr(i,j-i+1).size()>lps.size()) lps = A.substr(i,j-i+1);
                if(j-i+1>len){
                    len = j-i+1;
                    start = i, end = j;
                }
                i--, j++;
            }
            else break;
        }
    }
    for(int k = 0; k<A.size(); k++){
        int i = k, j = k;
        while(i>=0 and j<A.size()){
            if(A[i]==A[j]){
                // if(A.substr(i,j-i+1).size()>lps.size()) lps = A.substr(i,j-i+1);
                if(j-i+1>len){
                    len = j-i+1;
                    start = i, end = j;
                }
                i--, j++;
            }
            else break;
        }
    }
    for(int i = start; i<=end; i++) lps.push_back(A[i]);
    return lps;
}
