#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Well, this problem wasn't that difficult at all. We have to find the minimum health required by us to reach the bottom
            right corner, so we start from there only, and at each cell, we store the amount of energy we will have if we started
            with zero. Even if it is negative, we still store it. Now, if we are at a cell where this energy is positive, we store
            0 there. We believe that if we are at a positive health, we will not use any more energy. That is, we only need to
            consider where we suffer with negative energies, in case of positive, we take 0. Now, with that, at each cell,
            we take the maximum of its bottom and right cell, and add the current cells' energy to it, and then take the
            minimum of 0 and this new value. If you are not able to understand tthis, try to solve one example on paper. This
            is easy, i am not able to write the explanation in words.
 */

int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int r=dungeon.size();
    int c=dungeon[0].size();
    vector<vector<int>> dp(r,vector<int>(c));

    for(int i=r-1;i>=0;--i)
    {
        for(int j=c-1;j>=0;--j)
        {
            if(i==r-1 && j==c-1)    //Bottom-Right cell (Princess Cell)
                dp[i][j] = min(0,dungeon[i][j]);
            else if(i==r-1)   //last row
                dp[i][j] = min(0,dungeon[i][j]+dp[i][j+1]);
            else if(j==c-1)   //last col
                dp[i][j] = min(0,dungeon[i][j]+dp[i+1][j]);
            else
                dp[i][j] = min(0,dungeon[i][j]+max(dp[i][j+1],dp[i+1][j]));
        }
    }
    return abs(dp[0][0])+1;
}
