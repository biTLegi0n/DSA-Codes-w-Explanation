#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this question, we just need to figure out the fact that the minimum answer will come when we group all the
            person near the middle/median person. So we put the indices of all person in an array, find the median, and group
            all other around it.

 */

int seats(string str) {
    vector <int> v;
    for(int i = 0; i<str.size(); i++) if(str[i]=='x') v.push_back(i);

    int mid = v.size()/2;
    int count = 1;
    long long ans = 0;
    for(int i=mid-1; i>=0; i--){
        ans += v[mid]-v[i]-count;
        count++;
    }
    count = 1;
    for(int i = mid+1; i<v.size(); i++){
        ans += v[i]-v[mid]-count;
        count++;
    }
    return ans%10000003;
}
