#include <bits/stdc++.h>
using namespace std;

/**
 * @brief  Just start with each number from 0-9 and in each recursive call, move by one point and if the num is in range, store it
 *         The concept of both solutions is same. We process from all the digits and check the numbers that lie in our range.
 *
 */

// This solution is based on BFS 
vector<int> stepnum(int A, int B) {
    queue <int> q;
    for(int i = 0; i<=9; i++) q.push(i);
    
    unordered_map <int,int> mp;
    vector <int> ans;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        
        if(num>B) continue;
        if(mp.find(num)!=mp.end()) continue;
        mp[num]++;
        
        if(num>=A and num<=B) ans.push_back(num);
        
        int last = num%10;
        num*=10;
        int temp = num;
        if(last!=9) {
            temp += (last+1);
            q.push(temp);
        }
        temp = num;
        if(last!=0) {
            temp += (last-1);
            q.push(temp);
        }
    } 
    sort(ans.begin(),ans.end());
    return ans;
}


// This solution is based on recursive approach
set <int> res;
void check(int n, int low, int high){
    if(n>high) return;

    if(n>=low and n<=high) res.insert(n);

    int last = n%10;
    if(last!=9)
        check((n*10)+last+1,low,high);
    if(last!=0)
        check((n*10)+last-1,low,high);
}
vector<int> stepnum(int A, int B) {
    res.clear();
    for(int i = 0; i<=9; i++)
        check(i,A,B);
    vector <int> ans;
    for(auto u : res) ans.push_back(u);
    return ans;
}
