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
int visited[10004][10004];
int arr[10004][10004];
int dx[] = {1, 0, -1, 0};       // These two Global array are declared to avoid writing all the four/six conditions 
int dy[] = {0, 1, 0, -1};       // With the help of these arrays and a for loop, we can write all those condn in just 2 lines

bool isvalid(int x, int y){
    if(x<0 || y<0 || x>n || y>m)        // <0 OR >n tells if they are out of matrix
        return false;
    
    if(visited[x][y] == 1 || arr[x][y] == 0)       // arr[x][y] == 0 is checked because we wanted to count number of conn. components
        return false;

    return true;
}

void dfs(int x, int y){
    visited[x][y] = 1;

    for(int i = 0; i<4; i++){
        if(isvalid(x + dx[i], y + dy[i]))       // USE of those two global arrays
            dfs(x+dx[i], y + dy[i]);
    }
}

int main()
{
    FAST;

    cin>>n>>m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            visited[i][j] = 0;
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>arr[i][j];

    int count = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
          if(visited[i][j] == 0 && arr[i][j] == 1)
            count++, dfs(i, j);
    
    cout<<"Count of Connected Components is : "<<count<<"\n";
    
}