/**
 * @file XOR_queries.cpp
 * @author biTLegi0n
 * @brief 
 * @version 0.1
 * @date 2021-07-02
 * 
 * @copyright Copyright (c) 2021
 * 
 * Problem : 
 * 1310. XOR Queries of a Subarray
    Medium
    Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.

    

    Example 1:

    Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
    Output: [2,7,14,8] 
    Explanation: 
    The binary representation of the elements in the array are:
    1 = 0001 
    3 = 0011 
    4 = 0100 
    8 = 1000 
    The XOR values for queries are:
    [0,1] = 1 xor 3 = 2 
    [1,2] = 3 xor 4 = 7 
    [0,3] = 1 xor 3 xor 4 xor 8 = 14 
    [3,3] = 8
 */
#include <bits/stdc++.h>
using namespace std;
/*
    Using a simple trick that A^A is always 0. We got to this algorithm. Here, we see that if left limit is 0, that is we will
    directly return the prefix of R. and if its not zero, then we cancel out XOR of all the number less than L.
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector <int> prefix(arr.size());
        prefix.front() = arr.front();
        for(int i = 1; i<arr.size(); i++){
            prefix[i] = arr[i]^prefix[i-1];
        }
        
        vector <int> res;
        for(auto u : queries){
            int a = u[0];
            int b = u[1];
        
            if(a == 0)
                res.push_back(prefix[b]);
            else
                res.push_back(prefix[b]^(prefix[a-1]));
        }
        return res;
    }
};