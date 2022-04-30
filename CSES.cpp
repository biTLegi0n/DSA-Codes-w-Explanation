#include<bits/stdc++.h>
#define vi vector <ll>
#define vl vector <long long>
#define vc vector <char>
#define vp vector <pair <ll, ll> >
#define INF ll_MAX
#define MIN ll_MIN
#define pb push_back
#define mod 998244353
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int main()
{
    FAST;

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if((n==1 and m>2 ) or ( m==1 and n>2)) cout<<"-1\n";
        else{
            int ans = min(m,n)-1;
            int row = ans, col = min(m,n);
            if(row==n and col==m) cout<<ans<<"\n";
            else{
                if(n-row>0){
                    if((n-row)%2) ans += ((n-row)*2)+1;
                    else ans += (n-row)*2;
                }
                else{
                    if((m-col)%2) ans += ((m-col)*2)+1;
                    else ans += (m-col)*2;
                }
                cout<<ans<<"\n";
            }
        }
    }
}
