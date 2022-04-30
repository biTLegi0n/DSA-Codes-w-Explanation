// This is a trick to count the number of bits in a range. Its optimal.
//https://www.youtube.com/watch?v=g6OxU-hRGtY

#include <bits/stdc++.h>
using namespace std;

int solve(int A) {
    int ans = 0;
    
    if(A == 0)
        return 0;
    
    long long int maxPow = log2(A);
    
    long long int x = (1<<maxPow)%1000000007;
    
    return (maxPow*(x/2) + A-x+1 + solve(A-x))%1000000007;
}
