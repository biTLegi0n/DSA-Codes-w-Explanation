#include<bits/stdc++.h>
#define vi vector <int>
#define vl vector <long long>
#define vc vector <char>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

/*
    Problem : You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of 
              an envelope. One envelope can fit into another if and only if both the width and height of one envelope are greater 
              than the other envelope's width and height. Return the maximum number of envelopes you can Russian doll 
              (i.e., put one inside the other). Note: You cannot rotate an envelope.

    Example 1:
        Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
        Output: 3
        Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

    Example 2:
        Input: envelopes = [[1,1],[1,1],[1,1]]
        Output: 1

    ~Approach~ : This question is a approach of LIS. We are given a vector of vectors and we need to now find the LIS. 
                 We are finding the LIS because through that, we can know how many envelopes can be stubbed in other envelopes.
*/

// This compare function is used to compare two vectors. We can make our own whenever we need
// greater <int>() can be replaced with something like this
 bool compare(vector <int> &a, vector <int> &b){
    return (a.front() < b.front() and a.back() < b.back());
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    // sort if initially they are not sorted.
  
    sort(envelopes.begin(), envelopes.end());
    // To store the max LIS till that point
  
    vector <int> russian(envelopes.size(), 1);
    
    for(int i = 0; i<envelopes.size(); i++){
        for(int j = i+1; j<envelopes.size(); j++){
            if(compare(envelopes[i], envelopes[j]))
                if(russian[i]+1 > russian[j])
                    russian[j] = russian[i]+1;
        }
    }
    int res = 0;
    for(auto u : russian)
        if(u > res)
            res = u;

    return res;
}

int main()
{
//   FAST;

    int n;
    cin>>n;
    // NOTE: Predefining the size of envelopes would cause errors as doing pb then would add beyond n
    vector <vector <int>> envelopes;
    for(int i = 0; i<n; i++){
        vi v(2);
        cin>>v[0]>>v[1];
        envelopes.pb(v);
    }

    cout<<"Maximum number of envelopes we can Russian Doll are : "<<maxEnvelopes(envelopes)<<"\n";
}