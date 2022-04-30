#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this problem, if we'd apply BFS from every 1, then it would've been a problem since that would've gave us Time
            Complexity issues. So, what we did instead is simple and straight. Now we push all the zeros to a queue first and
            mark their dist as 0. Now, we start popping elements from the queue one by one. Initially all the zeros are popped
            Then their 4 children are pushed in the queue, and while doing so, we update their distance to current dist + 1.
            This way, starting from zeroes in the queue, we end up filling up the dist[][] and we finally return it. :)

 */

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector <vector <int>> visited(m,vector<int>(n,0)), dist(m,vector<int>(n,1e9));
        queue <pair<int,int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            visited[x][y] = 1;

            for(int i = 0; i<4; i++){
                if(isvalid(x+dx[i], y+dy[i], m, n, mat, visited)){
                    if(dist[x+dx[i]][y+dy[i]]>dist[x][y]+1) {
                        dist[x+dx[i]][y+dy[i]] = dist[x][y]+1;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
            }
        }
        return dist;
    }
protected:
    bool isvalid(int x, int y, int m, int n,vector<vector<int>>& mat,vector<vector<int>>& visited){
        if(x<0 or x>=m or y<0 or y>=n) return false;
        if(mat[x][y]==0 and visited[x][y]) return false;
        return true;
    }
};