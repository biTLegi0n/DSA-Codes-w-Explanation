#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This problem is a 2d version of Largest Rectangle in Histogram problem whose notes can be found in dp->stack n' queue
            section. Do read them first and then follow up. Now in this problem, we have a matrix. In order to find the histogram
            of a binary matrix, we would need heights. Now, as you have seen, in the base problem, we had heights in the array
            and using those heights we computed the largest area, but here we have 0s and 1s. To get the heights, we move in
            each coloumn, from top -> bottom, and check for consecutive ones. That woule give us heights.
            For example, for a given matrix
                1 0 1
                1 1 0
                1 0 1

            Its heights matrix will be -
                1 0 1
                2 1 0
                3 0 1

            Now, after getting this, we can compute the area for each row by passing it in the function.
            ~TWIST~
            But the only twist in this problem is that we can take any permutation of coloumns, that is two coloumns can be
            exchanged with each other. "You are allowed to permutate the columns matrix i.e. you can arrange each of the column
            in any order in the final grid." Therefore we will need sorting in this problem. We sort the heights rows and then
            pass them in function.

            Also to save some space, we can save the count in the same matrix, because once we have the count, we dont need the
            upper elements.
 */

int largestrect(vector<int>&arr){
    // each element of array is considered as height and that height can form rectangle of base equal to
    // largest base which can be extended on both sides having heights >= current height
    int n = arr.size();

    vector <int> prefix(n,-1),suffix(n,n);

    stack <pair<int,int>> st;

    // smallest in front
    for(int i = 0; i<n; i++){
        if(st.empty()) st.push({arr[i],i});
        else{
            while(!st.empty() and arr[i]<st.top().first){
                suffix[st.top().second] = i;
                st.pop();
            }
            st.push({arr[i],i});
        }
    }

    // smallest in back
    for(int i = n-1; i>=0; i--){
        if(st.empty()) st.push({arr[i],i});
        else{
            while(!st.empty() and arr[i]<st.top().first){
                prefix[st.top().second] = i;
                st.pop();
            }
            st.push({arr[i],i});
        }
    }

    int area = 0;
    // Finding largest rectangle
    for(int i = 0; i<n; i++){
        area = max(area, arr[i]*(abs(prefix[i]-suffix[i])-1));
    }
    return area;
}

int solve(vector<vector<int> > &mat) {
    int m = mat.size(), n = mat[0].size();
    vector <vector<int>> hash(m,vector<int>(n,0));

    for(int j = 0; j<n; j++){
        for(int i = 0; i<m; i++){
            if(i==0) hash[i][j] = mat[i][j];
            else{
                if(mat[i][j]==1)
                    hash[i][j] = hash[i-1][j]+1;
            }
        }
    }

/*
    if we do not have to do permutations in our matrix to get the maximum area, we would not need to sort the hash array.
    But since we are asked to find the maximum area, therefore we sort the array now and find the maximum area possible from
    that sorted array. Also if you are doubting that sorting would lead to some other problems like change in order of elements
    that are above current cell, that will not happen since if are sorting each array, top to bottom, and if in a cell, we
    have 0 1 0 0 2 1, and below cell has 0 2 0 0 3 2, then that directly says that if we have a 2 at this cell, that means we
    have a 1 above this, which we have sorted and that will be on its top, because above array is also sorted because after sort
    these arrays will become [0 0 0 1 1 2] and [0 0 0 2 2 3]
*/

    for(auto &u : hash){
        sort(u.begin(),u.end());
    }

    int area = 0;
    for(int i = 0; i<m; i++){
        area = max(area,largestrect(hash[i]));
    }
    return area;
}
