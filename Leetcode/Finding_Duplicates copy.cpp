#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> res;
        /*
            In some cases, just like UNION-FIND, we might have to change the method according to our needs.
            Just as you might remember, in some question, similiar to this one, we did replace the array
            elements with -1 and here, as you can observe, we replace them with -1*nums[i]. The thing is,
            here, we are not looping with the elements again and again, we just go on with one loop, and just
            one step ahead...
            CATCH :  This code is for the cases where only one or two occurrences of the element. If the element
                     occurs more than twice, it fails. To do that problem, the best universal method is to replace
                     the array elements with +=n means increment (every_element%n) with 'n' and later find whose /n is
                     greater than 1. If we find that, that that index(which will also be an element) has repeated more
                     than once.
        */
        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1]<0) res.push_back(abs(nums[i]));
            else
            nums[abs(nums[i])-1] *= -1;
        }
        return res;
    }
};