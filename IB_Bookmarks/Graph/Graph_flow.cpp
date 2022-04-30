#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Run bfs twice, one from all the co-ordinates connected to red lake and other from blue lake.

            Mark the visited cell and count the cell which are visited in both bfs.

 */

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isvalid(int x, int y, int m, int n,vector<vector<int>>&visited){
    if(x<0 or x>=m or y<0 or y>=n) return false;
    if(visited[x][y]) return false;
    return true;
}
int solve(vector<vector<int> > &mat) {
    int m = mat.size(), n = mat[0].size();
    vector <vector<int>> v1(m,vector<int>(n,0)), v2(m,vector<int>(n,0));

    queue <pair<int,int>> q;
    for(int i = 0; i<m; i++) q.push({i,0});
    for(int i = 0; i<n; i++) q.push({0,i});
    // q.push({0,0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(!v1[x][y]){
            v1[x][y] = 1;
            for(int i = 0; i<4; i++){
                if(isvalid(x+dx[i],y+dy[i],m,n,v1) and mat[x+dx[i]][y+dy[i]]>=mat[x][y])
                    q.push({x+dx[i],y+dy[i]});
            }
        }
    }
    for(int i = 0; i<m; i++) q.push({i,n-1});
    for(int i = 0; i<n; i++) q.push({m-1,i});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(!v2[x][y]){
            v2[x][y] = 1;
            for(int i = 0; i<4; i++){
                if(isvalid(x+dx[i],y+dy[i],m,n,v2) and mat[x+dx[i]][y+dy[i]]>=mat[x][y])
                    q.push({x+dx[i],y+dy[i]});
            }
        }
    }

    int count = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(v1[i][j] and v2[i][j]) count++;
        }
    }
    return count;
}

