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
