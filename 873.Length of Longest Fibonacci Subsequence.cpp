/**
 * 873. Length of Longest Fibonacci Subsequence

A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].

Constraints:

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109

 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
        int ans=0;
        for(int i=1; i<arr.size(); i++){
            int left=0, right=i-1;
            while(left<right){
                if(arr[left]+arr[right]>arr[i]) right--;
                else if(arr[left]+arr[right]<arr[i]) left++;
                else {
                    dp[i][right]=1+dp[right][left];
                    left++;
                }
                ans=max(ans,dp[i][right]);
            }
        }
        return ans==0?ans:ans+2;
    }
};

/*
Alternate solution: (This gave me TLE. Although its time complexity is O(n^2logm) where m is the max value in arr)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map <int,int> mp;
        int ans=0;
        for(int i=0; i<arr.size(); i++) mp[arr[i]]=i;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                int len = 0;
                int first=arr[i], second=arr[j];
                while(mp[first+second]>0){
                    len++;
                    int temp=first;
                    first=second;
                    second=arr[mp[temp+second]];
                }
                ans=max(ans,len);
            }
        }
        return ans>0?ans+2:0;
    }
};
*/

/*
Notes:
---------

Detailed Explanation:
-------------------
Simple solution, we take a DP approach where dp[a][b] represents the max length of a fibonacci subsequence ending with arr[a] and arr[b]
To fill in a value to dp[a][b], we need to find a value c such that dp[b][c]=dp[a][b]+1
More explanation in tech dose video: https://www.youtube.com/watch?v=s9I8KQZYh1M
Key Points:
----------

Example Walkthrough:
------------------
*/

