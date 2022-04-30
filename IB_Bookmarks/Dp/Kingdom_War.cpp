#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This question was the easiest and yet i was not able to solve it. Well, it is said in the question that a row elements
            are greater than its previous row and coloumn elements are greater than previous coloumn. Now, based on this fact, we
            can say that the largest element will be the last element of matrix. Therefore, we start from the last element of the m
            matrix, and traverse to the last row and last coloumn. From there, we find the sum, and then we say that
                    dp[i][j] = mat[i][j] + (dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1])
            we substract dp[i+1][j+1] because practically, it is added twice, so the have the correct answer, we subtract its one
            occurrance.

 */

int solve(vector<vector<int> > &mat) {
    int m = mat.size(), n = mat[0].size();
    vector <vector <int>> dp(m,vector<int>(n));

    int sum = 0;
    for(int i = m-1; i>=0; i--){
        sum += mat[i][n-1];
        dp[i][n-1] = sum;
    }
    sum = 0;
    for(int j = n-1; j>=0; j--){
        sum += mat[m-1][j];
        dp[m-1][j] = sum;
    }

    for(int i = m-2; i>=0; i--){
        for(int j = n-2; j>=0; j--){
            dp[i][j] = mat[i][j] + (dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1]);
        }
    }

    int ans = INT_MIN;
    for(auto u : dp){
        for(auto x : u)
            ans = max(ans,x);
    }
    return ans;
}
