#include<bits/stdc++.h>
#define vi vector <ll>
#define vl vector <long long>
#define vc vector <char>
#define vp vector <pair <ll, ll> >
#define INF ll_MAX
#define MIN ll_MIN
#define pb push_back
#define mod 998244353
#define mpp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

unordered_map <ll,ll> mp;

ll fun(ll n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(mp.find(n)!=mp.end()) return 1;

    ll temp = n;
    while(temp--){
        if(mp.find(temp)!=mp.end()){
            cout<<"now jump to "<<temp<<"\n";
            return 1+fun(n-temp);
        }
    }
    return -1;
}

int main()
{
    FAST;

    ll t;
    cin>>t;

    ll num = 1;
    for(ll i = 1; i<=40; i++){
        num = num*2;
        mp[num]++;
    }

    num = 1;
    ll res = 1;
    for(ll i = 1; i<=12; i++){
        res *= num;
        mp[res]++;
        num++;
    }

    while(t--){
        ll n;
        cin>>n;

        cout<<fun(n)<<"\n";
    }
}