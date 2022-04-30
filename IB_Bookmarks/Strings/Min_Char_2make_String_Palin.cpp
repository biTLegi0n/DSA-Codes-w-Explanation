#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   In actual, the problem ask to find the number of characters to add to the front. Now, Whenever we have something that ask to
 *          add characters in front or back, we usually think of an approach using KMP. So here, thinking in terms of KMP, we just need to
 *          add the reverse of the string at the back, so that, at the last character, we will have a length of the longest palindromic
 *          prefix which tells us the number of characters we have to add at the back!!!
 *
 * @param A
 * @return int
 */

int solve(string A) {
    string temp = A;
    reverse(temp.begin(),temp.end());
    A.append('$'+temp);
    vector <int> pi(A.size(),0);
    for(int i = 1; i<A.size(); i++){
        int j = pi[i-1];
        while(j>0 and A[i]!=A[j]) j=pi[j-1];
        if(A[i]==A[j]) j++;
        pi[i]=j;
    }
    return temp.size()-pi[A.size()-1];
}

