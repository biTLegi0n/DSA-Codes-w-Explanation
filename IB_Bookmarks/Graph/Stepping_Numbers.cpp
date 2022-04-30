#include <bits/stdc++.h>
using namespace std;

/**
 * @brief  Just start with each number from 0-9 and in each recursive call, move by one point and if the num is in range, store it
 *
 */

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
