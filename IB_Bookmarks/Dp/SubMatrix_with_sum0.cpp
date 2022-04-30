#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This problem is a combination of two subproblems.
            - Finding the target sum in an array which we have done so many times before
            - Storing the information of multiple rows in one row, just like we did in largest rectangle in matrix problem.

            Now, 1st one is not required to be explained. Let me elaborate 2nd. So we go to a row, and for each row,
            for the submatrix below it, we make a 1d array of size = number of coloumns and at each position is the sum of
            all the elements at that coloumn below that row. Then we pass this 1d array to the function fn to find the target
            sum. We return its count and add it in final result.

            Now i dont exactly have the answer to the question of why we are taking the lower rows and not upper rows, but it is
            important that we take the lower ones only. Taking the upper ones gives us WA.

 */

int fn(vector<int> &arr){
    int n=arr.size();
    unordered_map<int, int> prevSum;
    int res = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++) {
        currsum += arr[i];
        if (currsum == 0)
            res++;
        if (prevSum.find(currsum) != prevSum.end())
            res += (prevSum[currsum]);
        prevSum[currsum]++;
    }

    return res;
}
int solve(vector<vector<int> > &A) {
    if(A.size()==0)return 0;
    int m=A.size(),n=A[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        vector<int> t(n,0);

        // Take care of this thing here. We need to consider the lower rows and not the upper rows. I dont know the exact reason
        // behind this but if we dont' do that, we get WA. So we consider the rows below that current row.
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++){
                t[k]+=A[j][k];
            }
            ans+=fn(t);
        }
    }
    return ans;
}