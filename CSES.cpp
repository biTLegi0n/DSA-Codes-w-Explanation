#include<bits/stdc++.h>
#define vi arrtor <ll>
#define vl arrtor <long long>
#define vc arrtor <char>
#define vp arrtor <pair <ll, ll> >
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
        int n, k;
        cin >> n >> k;

        vector <int> arr(n), temp(n,1), v;

        for(int i = 0; i<n; i++) cin>>arr[i];

        int count = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if(2*arr[i]>arr[i-1]){
				count++;
			}
			else{
				count=0;
			}
			if(count==k){
				ans++;
			}
			else if(count>k){
				count--;
				if(count==k){
					ans++;
				}
			}
        }

        cout<<ans<<"\n";
    }
}