#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF 99999999
#define MIN -99999999
#define pb push_back
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int n, m;
int arr[10005][10005];
int visited[10005][10005];
int d[10005][10005];
int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
// All kind of motions are valid, ie sidewise as well as diagonal
bool isvalid(int x, int y){
    if(x < 0 || x > n || y < 0 || y > m)
        return false;
    if(visited[x][y])
        return false;
    
    return true;
}

// Similiar BFS using Queue
void bfs(int x, int y){
    visited[x][y] = 1;
    queue <pair <int, int > > q;

    q.push(mp(x, y));
    d[x][y] = 0;

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop();

        for(int i = 0; i<8; i++){
            if(isvalid(curr_x + dx[i], curr_y + dy[i])){
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];

                d[new_x][new_y] = d[curr_x][curr_y] + 1;
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y});
            }
        }
    }    
}

int main()
{
    FAST;

    cin>>n>>m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            visited[i][j] = 0, d[i][j] = 0;
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>arr[i][j];
    
    bfs(0, 0);

    for(int i = 0; i<n; i++){
        for(int j=i; j<m; j++)
            cout<<"Distance of node "<<i<<" and "<<j<<" from 1st is : "<<d[i][j]<<"\n";
        cout<<"\n";
    }
}