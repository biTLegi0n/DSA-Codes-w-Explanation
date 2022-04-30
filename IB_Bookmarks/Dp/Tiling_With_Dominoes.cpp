#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Here, in this problem, we will have two ways. First of all, refer to this link :
                    https://www.geeksforgeeks.org/tiling-with-dominoes/

            Now, here you can observe that we have two ways to fill up the spaces. We name them as
            A, and B.
            > A is when we fill the array such that the last coloum is filled completely without leaving any cell  vacant.
            > B is when we fill the array such that there is a vacant cell in the last cell.

            Now, for A, the base case will be A[0] = 1, means at last col, when we have filled up everything, it will be one way
            For B, the base case will be B[1] = 1, because since there is one vacant cell, thus to fill it, we would need one
            extra coloumn so as we can have one horixontal and one vertical dominoes fitted there to fill it completely.
            Note that B[0] will be 0 because if there is one cell left at last coloumn, there is no way to fill it.

            Thus, the recurrance relation is something like below, A[i] = 1 way to fill them without leaving any space, 2 ways to
            fill them such as one cell is left vacant,(one on the top, and one at the bottom).
            and B[i] = 1 way such that next one coloumn is consumed and 1 way such that we have maintained the same structure and
            thus consumed 2 coloumns.

            For better understanding, please open the link
 */

int solve(int n) {
    if(n%2) return 0;

    vector<long long> a(n+1,0), b(n+1,0);
    int mod = 1000000007;

    a[0] = 1, b[1] = 1;
    a[1] = 0, b[0] = 0;
    for(int i = 2; i<=n; i++){
        a[i] = (a[i-2]%mod + 2*b[i-1]%mod)%mod;
        b[i] = (a[i-1]%mod + b[i-2]%mod)%mod;
    }
    return a[n]%mod;
}
