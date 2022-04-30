#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

class Solution {
public:
    // We observe that whenever we have a peak, we remove that peak and keep removing the peak, since that
    // leads to a larger number. So we have to remove the peaks and make a monotonic increasing number and
    // To achieve that goal, the best way is to use stack (Increasing stack)
    string removeKdigits(string num, int k) {
        stack <char> st;
        if(k==0) return num;
        for(int i = 0; i<num.size(); i++){
            if(st.empty()){
                if(num[i]!='0') st.push(num[i]);
            }
            else{
                if(num[i]>=st.top()) st.push(num[i]);
                else{
                    while(!st.empty() and k>0 and num[i]<st.top())
                        st.pop(), k--;
                    if(st.empty() and num[i]=='0') continue;
                    st.push(num[i]);
                }
            }
        }
        while(!st.empty() and k>0) st.pop(), k--;
        string res = "";
        while(!st.empty()) res.push_back(st.top()), st.pop();
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
    }
};