#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   This question was interesting! The only reason i wasted so much time on it was that i thought it has to be done
 *          in O(nlogn), thats why i kept figuring out the problem with my binary search approach. But this question demands
 *          O(n^2). For O(n*n) too, i wasted some time. Actually, what i did was that i fixed left and right first and then
            i was looking for the middle element but that did not work. Why? Coz in that case, there could be cases where we
            shift the left or right and that change our actual answer. Also it is better to fix one of the three instead of two
            So later, after taking lots of hints, i fixed one of the three, the first one, and then using the basic two pointers
            approach found the remaining two numbers. Finding the remaining two by comparing the difference of the sum with target.

    @note   After doing this quesiton, the next quesiton, which is 3 some 0, can easily be solved.
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long res = 1e9;
        for(int i = 0; i<nums.size()-2; i++){
            int low = i+1, high = nums.size()-1;
            int sum = nums[i];
            while(low<high){
                long long temp = sum+nums[low]+nums[high];
                if(abs(temp-target)<abs(res-target))
                    res = sum+nums[low]+nums[high];
                if(temp>target) high--;
                else
                if(temp<target) low++;
                else return temp;
            }
        }
        return res;
    }
};