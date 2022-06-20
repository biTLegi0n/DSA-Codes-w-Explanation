#include<bits/stdc++.h>
using namespace std;

/**
  @brief    This is another good problem of Merge Sort. Here, at first, i kept thinking with monotonic stack, but later, a friend of mine told
            me to approach such problems with merge sort. Why? Because in merge sort, we divide the array in two halves untill there is only
            one element in the array, and when there is only one element in two arrays, its easy to compare that. Now, while merging the two
            arrays, we find the number of elements that are smaller than current element. How?
            Well, both the arrays are sorted, and left half is in left of right half. Thus, we know one thing for sure, that if there is an
            element that is smaller than current element in right half, it surely lies in its right. Therefore, this way, using two pointers, 
            we find all the elements smaller than an *index*.    
            Yes! Index. Since there could be multiple occurences of same number, we can not store the data on the basis of elements, therefore
            we store that on the basis of indices. And to store indices, we are preferrring vector only, coz map might throw TLE. s 
 */

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        vector <pair<int,int>> arr;
        for(int i = 0; i<nums.size(); i++) arr.push_back({nums[i],i});
        // map <pair<int,int>,int> mp;
        
        vector <int> mp(nums.size());
        mergesort(arr,mp);
        
        for(int i = 0; i<nums.size(); i++) res.push_back(mp[i]);
        return res;
    }
protected:
    void mergesort(vector <pair<int,int>> &nums, vector <int> &mp){
        if(nums.size()<=1) return;
        vector <pair<int,int>> left, right;
        int n = nums.size();
        for(int i = 0; i<n/2; i++) left.push_back(nums[i]);
        for(int i = n/2; i<n; i++) right.push_back(nums[i]);
        
        mergesort(left,mp);
        mergesort(right,mp);
        
        merge(left,right,nums,mp);
    }
    void merge(vector<pair<int,int>>&left,vector<pair<int,int>>&right,vector<pair<int,int>>&nums,vector <int> &mp){
        int i = 0, j=0, k=0;
        while(i<left.size() and j<right.size()){
            if(left[i].first<=right[j].first) nums[k++] = left[i], mp[left[i].second] += j, i++;
            else nums[k++] = right[j++];
        }
        while(i<left.size()) nums[k++] = left[i], mp[left[i].second] += right.size(), i++;
        while(j<right.size()) nums[k++] = right[j++];
    }
};
