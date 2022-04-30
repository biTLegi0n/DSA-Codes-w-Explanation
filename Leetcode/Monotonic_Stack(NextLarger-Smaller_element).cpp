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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")

using namespace std;

/*
    NOTE : THIS IS THE METHOD USED TO FIND THE NEXT LARGER/SMALLER ELEMENT OR THE PREVIOUS LARGER/SMALLER ELEMENT.
    In this method, we maintain a monotonically increasing or decreasing stack that works as explained.
        Increasing : We keep on adding elements as long as the current element is greater than the top(). Since it will
                     increase the overall nature of the stack making it monotonically incrasing. When we have a contradicting
                     element, we keep on popping the stack untill we have a top() which is smaller than the current, and the
                     contradicting element will become the next smallest element.
        Decreasing : We keep on adding elements as long as the current element is smaller than the top(). Since it will
                     dectease the overall nature of the stack making it monotonically decreasing. When we have a contradicting
                     element, we keep in popping the stack untill we have a top() which is larger than the current, and the
                     contradicting element will become the next largest element.

        [NOTE] -> pop() operation gives us the answer, so choose the stack (monotonically increasing or decreasing) accordingly
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // This question is an application of monotonically decreasing stack. Refer to notes [Algorithms]
        vector <int> res(temp.size());
        stack <pair<int,int>> s;
        for(int i=0; i<temp.size(); i++){
            if(s.empty()) s.push({temp[i],i});
            else{
                if(temp[i]<s.top().first) s.push({temp[i],i});
                else{
                    while(!s.empty() and temp[i]>s.top().first) res[s.top().second] = i-s.top().second, s.pop();
                    s.push({temp[i],i});
                }
            }
        }
        while(!s.empty()) res[s.top().second] = 0, s.pop();
        return res;
    }
};

int main()
{
    Solution ob;
    cout<<"Enter the number of elements : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : ";
    vector <int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector <int> res=ob.dailyTemperatures(arr);
    for(auto u : res) cout<<u<<" ";
    cout<<"\n";
}