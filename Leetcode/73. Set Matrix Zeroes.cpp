#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This question was simple yet tricky. The constraints of the problem did not allow us to use a particular number to
            denote the cells that will eventually be zeroes. Thus, we had to use 0 only. Now how do we do that. After spending
            a lot of time and taking some help, this came up.
            We can first check if the first row or coloum will be zero in final matrix. They will be zero if there is even a single
            zero in first row or coloum. After checking that, now we can alter these two. So we start from cell (1,1) and from there
            we check if a cell is zero, we mark its (0,j)th cell and (i,0)th cell as 0. Since we have already checked the final state
            of first row and col, thus we can now alter them. After doing so, now we just iterate over these rows and coloumns, and
            if a cell is 0, we make its corresponding rows and coloumns as zero. After doing that we come back to first row and col
            and now if any of them has to be 0, we make them 0.

 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, col = false;

        for(int i = 0; i<m; i++){
            if(matrix[i][0]==0){
                col = true;
                break;
            }
        }
        for(int j = 0; j<n; j++){
            if(matrix[0][j]==0) {
                row = true;
                break;
            }
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(matrix[i][j]==0)
                    matrix[0][j] = 0, matrix[i][0] = 0;
            }
        }

        // We have to start checking from 1 row and 1 col only or else we might alter the 0th row or col which would be wrong.
        for(int i = 1; i<m; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j<n; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 1; j<n; j++){
            if(matrix[0][j]==0){
                for(int i = 1; i<m; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row){
            for(int i = 0; i<n; i++){
                matrix[0][i] = 0;
            }
        }
        if(col){
            for(int i = 0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};