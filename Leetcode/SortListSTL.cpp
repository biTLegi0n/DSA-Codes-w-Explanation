#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main (){
    list <pair <int, int>> arr;

    // To sort a normal list in ascending order
    arr.sort();
    // To sort a list of pairs 
    arr.sort([](pair <ll int,ll int> const& a, pair <ll int,ll int> const& b) {
    if (a.second > b.second)
        return true;
    if (a.second < b.second)
        return false;
    return a.first < b.first;
    });

}