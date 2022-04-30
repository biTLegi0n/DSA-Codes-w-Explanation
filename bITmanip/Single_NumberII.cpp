/**
 * @file Single_NumberII.cpp
 * @author your name (you@domain.com)
 * @brief
 *
    Given an array of integers, every element appears thrice except for one which occurs once.

    Find that element which does not appear thrice.

    Note: Your algorithm should have a linear runtime complexity.

    Could you implement it without using extra memory?
 * @version 0.1
 * @date 2021-07-04
 *
 * @copyright Copyright (c) 2021
 *
  This approach is not intutive, You have to memorize it!
 */

#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &A) {
    /*int ones = 0;
    int twos = 0;
    for(auto ele: A)
    {
        ones = (ones^ele) & (~twos);        // ~ is for complement and ! is for negation
        twos = (twos^ele) & (~ones);
    }
    return ones;*/

    // No, the above one was not intuitive, but below one is!

    // vector <int> hash(32,0);
    int ans = 0;
    for(int i = 0; i<32; i++){
        int count = 0;
        for(int j = 0; j<A.size(); j++){
            if(A[j]&(1<<i)) count++;
        }
        // hash[i]=count;
        if(count%3!=0) ans += (1<<i)*1;
    }
    return ans;
}

// This method is not intutive