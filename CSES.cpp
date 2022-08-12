#include <bits/stdc++.h>
#define vi vector<ll>
#define vl vector<long long>
#define vc vector<char>
#define vp vector<pair<ll, ll>>
#define INF ll_MAX
#define MIN ll_MIN
#define pb push_back
#define mod 998244353
#define ll long long
#define FAST                                                                   \
	ios::sync_with_stdio(0);                                                   \
	cin.tie(0);                                                                \
	cout.tie(0)

using namespace std;

int main() {
	// FAST;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> arr(n);
        for(int i = 0; i<n; i++) cin>>arr[i];
        int count = 0;
        for(int i = 1; i<n-1; i++){
            if(arr[i]<arr[i-1] and arr[i]<arr[i+1]) count++;
        }
		vector <int> temp = arr;
        sort(arr.begin(), arr.end());
		vector <int> temp1;
		int i = 0, j = n-1;
        while(i<j){
            temp1.pb(arr[i]);
            temp1.pb(arr[j]);
            i++, j--;
        }
        for(auto u : temp1) cout<<u<<" ";
        cout<<"\n";
        if(temp == temp1){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
	}
}