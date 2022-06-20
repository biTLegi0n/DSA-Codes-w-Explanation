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

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
