#include <bits/stdc++.h>
using namespace std;

/**
   @brief   First thing about this problem. its constraints demand O(m*n*n) solution. So dont waste your time thinking of something better.
            Now, you must have noted the fact that in problems where we have to store the data of a submatrix or something like that, we go
            with prefix matrix. Like in the question, Largest Area of Rectangle, we did the same. Here too, we do the same. We make a prefix
            matrix, storing the sum of all the elements in a coloumn upto current cell. Now, we use this prefix matrix to compute our answer.
            So, as i said, this question demands a O(n^3), the third loop is actually to set a region of rows to be processed at a time. So
            we move down, row wise, and at each row, we proces all the submatrices, that could be formed between any row above it and current 
            row. Therefore, we run another loop, r, which starts from 0 to i, and using this loop, we update the current prefix row, by subtracting
            the values on that row, so that to eliminate all the subarrays above row r. Then, we will have a single array, the current row with 
            updated values, and we compute our answer with that. Doing so for all the row pairs will give our final answer. 

 */

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m,vector<int>(n,0));
        for(int j = 0; j<n; j++){
            int sum = 0;
            for(int i = 0; i<m; i++){
                sum += matrix[i][j];
                prefix[i][j] = sum;
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int r = 0; r<=i; r++){
                vector <int> arr = prefix[i];
                if(r==i) ans += fun(arr,target);
                else{
                    for(int j = 0; j<n; j++) arr[j] -= prefix[r][j];
                    ans += fun(arr,target);
                }
            }
        }
        return ans;
    }
protected:
    int fun(vector<int>&arr, int target){
        unordered_map <int,int> mp;
        int sum = 0, ans = 0;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            if(sum == target) ans++;
            if(mp.find(sum-target)!=mp.end()) ans += mp[sum-target];
            mp[sum]++;
        }
        return ans;
    }
};