#include <bits/stdc++.h>
using namespace std;

/**
   @brief     This question has the most beautiful observation out of all questions in DP. This little observation makes
              very easy. We should note that in most of the cases, if we are talking about the maximum product, it will
              occur starting from either of the side. for ex [-2,-3,-6,-2,-5], maximum product will be from last 4 digits
              if we have a positive +5 at last, max prod will be from all digits, because we now have even number of negatives. 
              So, in most of the cases, it will be from either of the sides. In case we get a 0 somewhere, we reset out storing 
              variable to 1, so that we do not get 0 always. So, in case of even negatives, we can multiply all the elements and 
              we will get a positive number which is greatest, and in case of odd number of negatives, we can compare the left 
              and right end products. Now, we do so because we know that product of any even number of negatives will eventually
              increase. And so, if we keep multiplying from the two ends, and skip the last negative, we will have the largest
              product of the array. Thus, we do that from both ends, and skip their corresponding last negatives. 
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