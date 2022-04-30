#include<bits/stdc++.h>
using namespace std;

// Just did what i was asked to do!!!

string convert(string A, int B) {
    if(B==1) return A;
    string res[B];
    int i = 0, j = 0;
    bool flag = true;       // true -> down,  false -> up
    while(j<A.size()){
        res[i].push_back(A[j]);
        j++;
        if(i==B-1) flag =false;
        else
        if(i==0) flag = true;

        if(flag) i++;
        else i--;
    }
    string str;
    for(auto u : res) str.append(u);
    return str;
}
