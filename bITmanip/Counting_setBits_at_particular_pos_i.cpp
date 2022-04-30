/**
 * @brief We count number of set bits at a particular position in this, then use that information 
 *      to get our result
 *  Step1 : Count the number of setBits at particular positions in a and b
    Step2 : Count the same in c. Check for two conditions.

    If we require 0 set bits and have more than 0 in a and b
    if we require 1 set bit and have 0 in both a and b

    If we require 0 then we will have to flip all the ones at that position in both a and b and if we require 1 then we have to make atleast one bit set in either a or b.


 */

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i<31; i++){
            int count = 0, req = 0;
            if(a & (1<<i))
                count++;
            if(b & (1<<i))
                count++;
            
            req = c & (1<<i) ? 1 : 0;
            
            if(req == 0){
                ans += count;
            }
            else
            if(req == 1 and count == 0)
                ans++;
        }
        return ans;
    }
};
