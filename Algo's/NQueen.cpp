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
int a[10][10];
int n;

bool isValid(int x, int y){
    cout<<"need to check isvalid("<<x<<" , "<<y<<"\n";
    for(int i = x; i>=0; i--){
        if(a[i][y] == 1)
            return false;
    }
    int row = x, col = y;
    while(row >= 0 && col >= 0){
        if(a[row][col] == 1)
            return false;
        row--, col--;
    }
    row = x, col = x;
    while(row < n && col >= 0){
        if(a[row][col] == 1)
            return false;
        row++, col--;
    }

    return true;
}

bool NQueen(int col){
    if(col >= n)
        return true;
    
    for(int i = 0; i<n; i++){
        //a[i][col] = 1;
        if(isValid(i, col)){
            cout<<i<<" , "<<col<<" is set as 1\n";
            a[i][col] = 1;
            if(NQueen(col+1))
                return true;
            
            cout<<i<<" , "<<col<<" is removed as 1 and set as 0\n";
            a[i][col] = 0;    
        }
    }
    return false;
}

int main()
{
  FAST;

    cin>>n;
    //int a[n][n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            a[i][j] = 0;
  
    if(!NQueen(0))
        cout<<"Not pOssible\n";
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}