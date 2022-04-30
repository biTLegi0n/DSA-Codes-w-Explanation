#include <bits/stdc++.h>
using namespace std;

/**
   @brief     This question has the most beautiful observation out of all questions in DP. This little observation makes
              very easy. We should note that in most of the cases, if we are talking about the maximum product, it will
              occur starting from either of the side. for ex [-2,-3,-6,-2,-5], maximum product will be from last 4 digits
              if we have a positive +5 at last, max prod will be from all digits. So, in most of the cases, it will be
              from either of the sides. In case we get a 0 somewhere, we reset out storing variable to 1, so that we
              do not get 0 always.
              Thatsall, that is the TRICK. From both sides, we check for maximum product. It will be from one of the sides.

 */

int maxProduct(const vector<int> &A) {
    int mx=INT_MIN;
    int res=1;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        res*=A[i];
                mx=max(mx,res);
        if(res==0)res=1;
    }
    res=1;
    for(int i=n-1;i>=0;i--)
    {
        res*=A[i];
                mx=max(mx,res);
        if(res==0)res=1;
    }
    return mx;
}