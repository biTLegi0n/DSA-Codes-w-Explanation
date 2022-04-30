#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
    if(m < n)
            swap(m, n);

    if(n == 0)
            return m;


    return gcd(m % n, n);
}