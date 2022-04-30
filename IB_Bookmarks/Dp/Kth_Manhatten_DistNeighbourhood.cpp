#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This problem again made me mad! Every question in this bucket is making me mad! I have to watch the solution to get AC
            Well, in this one, to get the kth maximum, we have to know the (K-1)th maximum. Thus dp[k] depends on dp[k-1] only.
            Now, that's the only logic. That we know dp[0], which is equal to the matrix itself. Then from there, by checking the
            adjacent 4 elements, we find dp[1], similiarly, dp[2,3,....k].
                During the process, we only need to take care of one thing. that dp[k] depends purely on dp[k-1], so don't update
            the dp values with already updated dp values. That will give you wrong answers. I mean, if you have found the maximum
            for row x, and now we are at row x+1, then while checking a cells' 4 adjacent elements, we would be checking the
            updated values of dp in upper row, which sometimes can give wrong answers. [Therefore], we make a temporary matrix
            which,  at every element, takes the previous dp value of that cell, and change the value in itself depending on previous
            values of dp. Rest can be seen in the code.

 */

vector<vector<int> > solve(int A, vector<vector<int> > &B){
    vector<vector<int>> dp=B;
    for(int k=1;k<=A;k++)
    {
        vector<vector<int>> h(B.size(),vector<int>(B[0].size()));
        for(int i=0;i<B.size();i++)
        {
            for(int j=0;j<B[0].size();j++)
            {
                h[i][j]=dp[i][j];
                if(i>0)
                    h[i][j]=max(h[i][j],dp[i-1][j]);
                if(i<B.size()-1)
                    h[i][j]=max(h[i][j],dp[i+1][j]);
                if(j>0)
                    h[i][j]=max(h[i][j],dp[i][j-1]);
                if(j<B[0].size()-1)
                    h[i][j]=max(h[i][j],dp[i][j+1]);
            }
        }
        dp=h;
    }
    return dp;
}