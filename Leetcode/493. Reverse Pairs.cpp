#include <bits/stdc++.h>
using namespace std;

/*
    This probelm is a very very good example of merge sort problems. Infact, problems like this where we have i<j and nums[i]< = > nums[j] are
    usually solved by merge sort concept. That is because, in merge sort, we break the array in two parts, and we ensure that left part is
    sorted and right part is sorted and we merge them using two pointers. So, our problem, in merge sort, is divided into two arrays, both 
    sorted and now we have to find our answer wrt them.
*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergesort(ans,nums);
        return ans;
    }
protected:
    void mergesort(int &ans, vector <int>&nums){
        if(nums.size()<=1) return;
        int mid = nums.size()/2;
       
        vector <int>left,right;
        for(int i = 0; i<mid; i++) left.push_back(nums[i]);
        for(int j = mid; j<nums.size(); j++) right.push_back(nums[j]);
        
        mergesort(ans,left);
        mergesort(ans,right);
        
        ans += fun(left,right);
        merge(left,right,nums);
    }
    void merge(vector <int>&a, vector<int>&b, vector<int>&c){
        int i = 0, j = 0, k = 0;
        while(i<a.size() and j<b.size()){
            if(a[i]<b[j]) c[k++] = a[i++];
            else c[k++] = b[j++];
        }
        while(i<a.size()) c[k++] = a[i++];
        while(j<b.size()) c[k++] = b[j++];
    }
    
    int fun(vector <int>&left, vector<int>&right){
        int i=left.size()-1, j=right.size()-1, ans = 0;
        while(i>=0 and j>=0){
            if(left[i]>(long long)2*right[j]){
                ans += j+1;
                i--;
            }
            else j--;
        }
        return ans;
    }
};