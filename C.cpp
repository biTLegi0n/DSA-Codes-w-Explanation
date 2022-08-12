#include<bits/stdc++.h>
#define vi vector <int>
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

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        
        ll a[n];
        for(ll i=0;i<n;i++)
        cin >> a[i];
        
        string s;
        for(ll i=0;i<n;i++){
            if(a[i]>q)
            s.push_back('0');
            else
            s.push_back('1');
        }
        string org = s;
        ll maxm=0;
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='0' && q>maxm){
                q--;
                s[i] = '1';
            }
            else if(s[i]=='1')
            maxm = max(maxm,a[i]);
        }
        int cz = 0, co = 0, idx = n-1;
        for(ll i = n-1; i>=0; i--){
            if(s[i]=='1') co++;
            else cz++;

            if(cz>q) break;
            if(cz>co) idx = i;
        }
        
        while(idx<n){
            if(org[idx]=='0') q--, org[idx]='1';
            else if(a[idx]>q) org[idx] = '0';
            idx++;
        }
        int so = 0, oo = 0;
        for(auto u : s) if(u=='1') so++;
        for(auto u : org) if(u=='1') oo++;
        if(so>oo) cout<<s<<"\n";
        else cout<<org<<"\n";
        // cout << s << endl;
        // cout<<org<< endl;
    }
}