#include <bits/stdc++.h>
using namespace std;

class Solution {
    void rotate(vector<vector<int> > &arr) {
        int n = arr.size();
        for(int i = 0; i<n/2; i++){
            for(int j = i; j<n-i-1; j++){
                int temp = arr[i][j];
                swap(arr[j][n-i-1],temp);
                swap(arr[n-i-1][n-j-1],temp);
                swap(arr[n-j-1][i],temp);
                swap(arr[i][j],temp);
            }
        }
    }
};
