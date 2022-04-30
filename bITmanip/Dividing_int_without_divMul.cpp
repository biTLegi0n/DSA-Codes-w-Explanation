#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 *Time take O(logn*logn)
            In the following problem, there are 2 intuitions. Though both of them are kinda same. But one seems more naive and another one
            is good looking.
            1. Since we are not supposed to use divide and modulo, but nothing has been mentioned regarding the use of addition and substrn.
               so we can keep on subtracting b from a until we have a<=b. And we count the number of iterations it took to reach that state.
               Just keep in mind about some test cases, like INT_MIN divided by -1, or INT_MAX divided by 1, Coz in those cases, if we don't
               handle them seperately, we might end up getting a TLE.
            2. Second is, that we keep two seperate variables, both type long long(so that we dont need to handle some cases seperately)
               and we subtract b times the nearest power of 2 from a. for example, if we want to divide 43 by 8, so in first iteration we
               subtract 8*4=32 from 43, since the (2nd power of 2)*8 is the nearest power multiple of b which is smaller than a. Now we add
               this power, ie, 2^2 to our answer, and update a from 43 to 43-32 = 11. Now we repeat the process. sub (0th power of 2)*8, ie 8
               then 11->3. Now, since a is smaller than 8, we stop. and our answer comes to be 5(4+1).

            NOTE: Remember to take long absolute(labs()) because, simple abs has a range of [MIN,MAX]

 * @param A -> dividend
 * @param B  -> divisor
 * @return int
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};