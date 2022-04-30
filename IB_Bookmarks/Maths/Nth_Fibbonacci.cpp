#include<bits/stdc++.h>
using namespace std;
/**
 * @brief basically, this code is to be written to be as it is. eVen minor changes in it can cause errors.
          What the approach says is that multiplying matrix [[1,1],[1,0]] n-1 times gives us nth fib num
          So now there are two ways to do so. One is linear O(n), that we multiply the matrix n-1 times with itself
          Another is power function that we do, known as binary exponentiation, whose complexity is O(logn).
          So here is the code for binary exponentiation.
            - Multiply function multiplies two 2x2 matrices.
            - Power function is the recursive function that is doing the job of binary exponentiation.
            Please not that unlike the earlier binary exponentiation code, we check the n to be odd after we multiply the matrices.
            This small thing is important to note or else we will get wrong answers.
 *
 */
#define mod 1000000007
void multiply(long long f[2][2], long long m[2][2]){
    long long x = m[0][0]*f[0][0] + m[0][1]*f[1][0];
    long long y = m[0][0]*f[0][1] + m[0][1]*f[1][1];
    long long z = m[1][0]*f[0][0] + m[1][1]*f[1][0];
    long long w = m[1][0]*f[0][1] + m[1][1]*f[1][1];

    f[0][0] = x%mod;
    f[0][1] = y%mod;
    f[1][0] = z%mod;
    f[1][1] = w%mod;
}

void power(long long f[2][2], int n){
    if(n==0 or n==1) return;

    long long m[2][2] = {{1,1},{1,0}};

    power(f,n/2);
    multiply(f,f);
    if(n%2)
        multiply(f,m);
}

int solve(int n) {
    //O(n) gives TLE
    // SOlving it using power of matrix concept
    long long m[2][2] = {{1,1},{1,0}}, f[2][2] = {{1,1},{1,0}};
    // So multiplying this matrix to itself n-1 times will give me fib_n
    // the matrix already contains {{fib2,fib1},{fib1,fib0}};
    power(f,n-1);
    return f[0][0];
}
