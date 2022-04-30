#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   Why? Why? Why i always make mistakes! Well, i guess because i have to learn from them!
            Well, in this question, the mistake i made was to not compare correctly!
            Since, the condition for making a triangle is that for a<b<c, a+b>c
            In order to satisfy this condition, the first thing to do is sort! After sorting, we use two pointers to find
            two numbers which are greater than third! Now, How should we handle this! The idea is simple! We need to move
            left and right in order to search for numbers and we need to do this in reference of a number which is fixed.
            [:] the mistake i made, which i mentioned before, was that i fixed the smaller number, ie a.
            instead, i should fix the larger number ie 'c', since c is only one, while a comes with b
            On this basis, we fix c, with for loop, and use two pointers for finding the correct pair of a,b. Once we find a
            pair a,b we add high-low to the answer, since if a(which is smaller) +b > c then in between a and b, the numbers are
            greater than a, so they have to be greater than a, which ensures that a+b>c
 */

int nTriang(vector<int> &A) {
   sort(A.begin(),A.end());
   long long res = 0;
    for(int i = A.size()-1; i>=2; i--){
        int low = 0, high = i-1;
        while(low<high){
            long long sum = A[low]+A[high];
            if(sum>A[i]) res+=high-low, high--;
            else low++;
        }
    }
    return res%1000000007;
}
