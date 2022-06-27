#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Z function is also very easy, like KMP. Just that its code has to be understood and remembered. 
            The pi array here gives us the length of longest prefix starting from i, which is also a prefix of string s. 
            For example, 
            For example, here are the values of the Z-function computed for different strings:

                "aaaaa" - [0,4,3,2,1]
                "aaabaab" - [0,2,1,0,2,1,0]
                "abacaba" - [0,0,1,0,3,0,1]

            Formally, this would be achieved in O(n^2), but by making some observations and using previously computed values, we can
            optimize its code and do the same in O(n).

            The brute force way is

                for (int i = 1; i < n; ++i){
                    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                        ++z[i];
                }

            But, we can add two more variables here, namely l and r, which will act as a range, whose values has already been computed.
            So, in this for loop, before running the while loop, we check if we are in the range. If we are, we set 
                pi[i] = min(pi[i-l],r-i+1)
            pi[i-l] is the value at the previous prefix character, which would be equal to current character, and r-i+1 length of current 
            prefix. So, we need to take the minimum of these two. It could be possible that the answer at previous character may be larger
            than the possible prefix lenght. Therefore, we need to take the minimum. 
            Now, after the while loop, we check if the r has been updated or not. 
            wE do if(r < i+pi[i]-1) r = i+pi[i]-1 and l = i 

            After all this, the overall complexity of z_function will be O(n). 

 * @param s 
 * @return vector<int> 
 */

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            pi[i] = min (r - i + 1, pi[i - l]);
        while (i + pi[i] < n && s[pi[i]] == s[i + pi[i]])
            ++pi[i];
        if (i + pi[i] - 1 > r)
            l = i, r = i + pi[i] - 1;
    }
    return pi;
}