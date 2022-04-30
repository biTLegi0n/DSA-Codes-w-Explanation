#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

ll mod = 1000000007;
ll dp[1000005];
ll inv[1000005];
/**
 * @brief
 *
 * IN polynomial Hash, we convert the string to hash in following way
 *          hash(s) = (s[0]*prime^0 + s[1]*prime^1 + s[2]*prime^2 ....... s[n-1]*prime^n-1) % MOD

 * Now, this gives me hash of whole string. If i want hash of a substring from here, what I need to note is
   that, i can have it in O(1). I maintain a DP[i] which stores the Hash value of a substring(0,i). So, we need
   to observe the fact that, hash(substr(i,j)) = [dp[j]-dp[i]] <- In this, we will have that substring's hash
   multiplied by some factor of prime(which is greater than the total set size of characters). Now that factor
   can easily be observed as prime^L. Dividing with that factor will give us the hash of that substr.
   The only thing that is a pain in a$$ is taking modulo. wE know how to take modulo of 1/b, that is modulo inverse.
   So for the divding factor, we have to take modulo inverse, which by fermat's theorem, is prime^MOD-2

   Time  :  O(nlogn+m) // for modulo division
   If we change this code to convert it to rabin karp, then its complexity will be O(n+m). That's because we remove the
   modulo inverse factor from it which removes the logn time which we were using.
 */
ll power(long long x, ll y){
    ll res = 1;
    x = x%mod;

    if(x==0) return 0;

    while(y>0){
        if(y%2==1)
            res = (res*x)%mod;
        y=y/2;
        x=(x*x)%mod;
    }
    return res;
}

ll get_hash(ll l, ll r){
    ll res = 1;
    if(l==0) return dp[r];
    res = ((dp[r]-dp[l-1]+mod))%mod;
    res = (res*inv[l])%mod;
    return res;
}

vector <ll> fun(string pat, string str){
    vector <ll> res;

    ll p = 31;
    ll prime = 1;
    ll h = (str[0]-'a'+1);
    dp[0] = h;
    inv[0] = 1;
    for(ll i = 1; i<str.length(); i++){
        prime=(prime*p)%mod;
        h = ((str[i]-'a'+1)*prime)%mod;
        dp[i] = (dp[i-1]+h)%mod;
        inv[i] = power(prime,mod-2);
    }

    p = 31;
    prime = 1;
    ll pat_hash = (pat[0]-'a'+1);
    for(ll i = 1; i<pat.length(); i++){
        prime=(prime*p)%mod;
        pat_hash += ((pat[i]-'a'+1)*prime)%mod;
    }

    for(ll i = 0; i<str.length()-pat.length()+1; i++){
        if(get_hash(i,i+pat.length()-1) == pat_hash)
            res.push_back(i);
    }
    return res;
}

int main(){
    ll n;
    while(cin>>n){
        string pat, str;
        cin>>pat>>str;

        vector <ll> arr = fun(pat,str);
        for(auto u : arr)
            cout<<u<<"\n";
    }
}