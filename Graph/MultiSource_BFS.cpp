#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This concept is used when we have to find a shortest distance from multiple sources. For example, if we want to find
            a shortest distance of any zero from any one, then we will have to push all the ones to a queue at once. Since we are
            using all the ones as sources, thus this is know as multisource.
            Everything else is same, just that we pass all the ones at once. Also note that if we want to solve such questions in
            an alternate way, then we have to run the while loop inside a for loop to check the distance of every 0 from 1. But this
            way, we push all the ones at once and then everything else is same.

 */

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector <vector <int>> visited(m, vector<int>(n,0)), dist(m,vector<int>(n,1e9));

        queue <pair<int,int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==2)
                    q.push({i,j}), dist[i][j] = 0;
                else if(grid[i][j]==0) dist[i][j] = 0;
            }
        }

        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            visited[x][y] = 1;
            for(int i = 0; i<4; i++){
                if(isvalid(x+dx[i], y+dy[i], m, n, grid, visited)){
                    if(dist[x+dx[i]][y+dy[i]]>dist[x][y]+1)
                        dist[x+dx[i]][y+dy[i]] = dist[x][y]+1, q.push({x+dx[i], y+dy[i]});
                }
            }
        }
        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] and grid[i][j]==1)
                    return -1;
                ans = max(ans, dist[i][j]);
            }
        }
        return ans==1e9 ? -1 : ans;
    }
protected:
    bool isvalid(int x, int y, int m, int n,vector<vector<int>>& grid,vector<vector<int>>& visited){
        if(x<0 or x>=m or y<0 or y>=n) return false;
        if(grid[x][y]==0 or grid[x][y]==2 and visited[x][y]) return false;
        return true;
    }
};