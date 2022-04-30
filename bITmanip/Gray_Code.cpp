/**
 * @brief
 *
 I try to give a simple proof here. Let's denote i^(i>>1) as f(i). To proof f(i) is the ith gray code, we only need to prove the following statements:

    f(0) = 0
    (i) and f(i+1) only differs in one digit
    f(i) is bijective, e.g. f(i) = f(j) if and only if i = j.

The first one is obvious.

For the second , f(i) ^ f(i+1) = i^(i>>1)^(i+1)^((i+1)>>1) = (i^(i+1)) ^ ((i^(i+1)) >> 1). Let's denote g(i) = i^(i+1), g(i) has the form of
                0000111...111. So f(i) ^ f(i+1) = g(i) ^ g(i)>>1 = 00001000...000.

The third part can be proved alike.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //This is a formula based problem.. We have to think of this formula only!
    vector<int> grayCode(int n) {
        vector <int> res(1<<n);

        for(int i = 1; i<(1<<n); i++){
            res[i] = i^(i>>1);
        }
        return res;
    }
};
