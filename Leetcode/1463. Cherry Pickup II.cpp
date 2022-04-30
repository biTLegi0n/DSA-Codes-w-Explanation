#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This problem was pretty simple. I first made a mistake where i tried to run two dfs calls, one for each robot but
            the problem with that is that we cannot keep track of the path of first robot. Thus we have to run both robots
            together. Now after taking some help, i got to know that we should run both of them together and since they will
            run together, their row will never change. ie they will reach every row at the same Time. Thus the three parameters
            that change are x, y1 and y2. Now, One more thing to take care of in this question is the case when both the robots
            stand at same cell. In that case, we only need to add the value of the cell to the answer once. After these things
            in mind, this question is a simple DFS. and memoize that for optimized solution.

 */

class Solution {
public:
    int dy[3] = {-1,0,1};
    int dp[75][75][75];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,grid[0].size()-1,grid);
    }
protected:
    bool isvalid(int x, int y, int m, int n){
        if(x<0 or x>=m or y<0 or y>=n) return false;
        return true;
    }

    int fun(int x, int y1, int y2, vector<vector<int>>&grid){

        if(dp[x][y1][y2]!=-1) return dp[x][y1][y2];

        int ans = 0;
        for(int i = 0; i<3; i++){
            if(isvalid(x+1,y1+dy[i],grid.size(),grid[0].size())){
                for(int j = 0; j<3; j++){
                    if(isvalid(x+1,y2+dy[j],grid.size(),grid[0].size())){
                        ans = max(ans,fun(x+1,y1+dy[i],y2+dy[j],grid));
                    }
                }
            }
            else
            if(x==grid.size()-1){
                if(y1==y2) return dp[x][y1][y2] = grid[x][y1];
                return dp[x][y1][y2] = grid[x][y1]+grid[x][y2];
            }
        }

        if(y1==y2) return dp[x][y1][y2] = grid[x][y1];
        return dp[x][y1][y2] = grid[x][y1]+grid[x][y2]+ans;
    }
};