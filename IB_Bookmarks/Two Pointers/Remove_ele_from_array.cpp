#include<bits/stdc++.h>
using namespace std;

// Behuda sawaal h bc! bss ye dekhte jaao ki elements match ho rhe h ya nhi!
// Agar ho rhe h to skip, nhi ho rhe to equate karke main pointer ko aage badha de

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]!=val)
                nums[k]=nums[i],k++;
        }
        return k;
    }
};