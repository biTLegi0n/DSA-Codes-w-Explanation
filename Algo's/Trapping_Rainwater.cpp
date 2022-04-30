/**
 * @brief Trapping Rainwater, differnt approaches
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Brute force will be find left max and right max for each block, taking complexity to O(n^2)
// better Brute Force ... O(3N), Since we use space...thats why this is only better
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> lmax(n), rmax(n);
        
        int left = 0, right = 0;
        // Searching for left max
        for(int i = 0; i<n; i++){
            lmax[i] = left;
            left = max(left, height[i]);
        }
        // Searching for right max
        for(int i = n-1; i>=0; i--){
            rmax[i] = right;
            right = max(height[i], right);
        }
        
        int total_water = 0;
        for(int i = 0; i<n; i++){
            int water = min(lmax[i], rmax[i]) - height[i];
            // WATER wil overflow
            if(water < 0)
                continue;
            total_water += water;
        }
        return total_water;
    }
};

// Optimal
/*
Here is my idea: instead of calculating area by height*width, we can think it in a cumulative way. In other words, sum water amount 
of each bin(width=1). Search from left to right and maintain a max height of left and right separately, which is like a one-side 
wall of partial container. Fix the higher one and flow water from the lower part. For example, if current height of left is lower, 
we fill water in the left bin. Until left meets right, we filled the whole container.
*/
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1, water = 0, i = 0;
        int lmax = arr[left], rmax = arr[right];
        
        while(left < right){
            if(arr[left] < arr[right]){
                if(arr[left] < lmax)
                    water += lmax-arr[left];
                else
                    lmax = arr[left];
                
                left++;
            }
            else{
                right--;
                
                if(arr[right] < rmax)
                    water += rmax-arr[right];
                else
                    rmax = arr[right];
            }
        }
        return water;
    }
};