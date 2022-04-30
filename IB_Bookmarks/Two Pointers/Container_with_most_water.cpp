#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &A) {
    int ans = 0;
    int low = 0, high = A.size()-1, maxl=0, maxr=0, li,ri;
    while(low<high){
        if(A[low]>maxl) maxl = A[low],li=low;
        if(A[high]>maxr) maxr = A[high],ri=high;

        ans = max(ans,(ri-li)*(min(maxl,maxr)));
        if(maxl>maxr) high--;
        else low++;
    }
    return ans;
}
