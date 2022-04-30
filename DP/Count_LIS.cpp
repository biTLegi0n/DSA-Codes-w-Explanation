/**
 * Here we had to count the LIS. So we maintained another array named count.
 * The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing Subsequence and the
 * coresponding number of these sequence which ends with nums[i], respectively. That is:
 *
 * len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
 *
 * cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].
 *
 * Then, the result is the sum of each cnt[i] while its corresponding len[i] is the maximum length.
 *
 * For example, we have nums = [1,3,5,4,7]. Then after we have processed till 4, our len and count array will be like
 *                       len = [1,2,3,3,4]
 *                     count = [1,1,1,1,2].
 * We see that when we have two increasing subseq of len 3, and need one more element to increase both lengths to 4, then we have a
 * number of count1 + count2 ways to find a lIS of length 4. Thats why we add both count[i] and count[j] when len[i] == len[j]+1
 * Thats because when we have len[i] already equal to len[j]+1 means that there already exists a subseq which can make an LIS of len[j]+1
 * so we need to count its number of ways too!
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector <int> len(nums.size(), 1);
        vector <int> count(nums.size(), 1);

        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(len[i] < len[j]+1){
                        len[i] = len[j]+1;
                        count[i] = count[j];
                    }
                    else
                    if(len[i] == len[j]+1){
                        count[i] += count[j];
                    }
                }
            }
        }

        int ans = 0, maxLen = 0;
        for(auto u : len){
            if(u > maxLen)
                maxLen = u;
        }

        for(int i = 0; i<len.size(); i++){
            if(len[i] == maxLen)
                ans += count[i];
        }
        return ans;
    }
};