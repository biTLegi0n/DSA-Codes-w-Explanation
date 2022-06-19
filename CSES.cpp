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

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> ans;
        if(s[0]=='9')
        {
            bool flag = true;
            for(int i=s.size()-1;i>=0;i--)
            {
                if((s[i]=='0' or s[i]=='1') and flag)
                    ans.push_back(1 - (s[i]-'0'));
                else if(flag)
                {
                    ans.push_back(11 - (s[i]-'0'));
                    flag = !flag;
                }
                else if(s[i]=='0')
                {
                    ans.push_back(0);
                    flag = !flag;
                }
                else
                    ans.push_back(10 - (s[i]-'0'));
            }
        }
        else{
            for(int i=s.size()-1;i>=0;i--) ans.pb(9 - (s[i]-'0'));
        }
        
        reverse(ans.begin(),ans.end());
        for(auto u: ans)
            cout<<u;
        cout<<endl;
    }
}