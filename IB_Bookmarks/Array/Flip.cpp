#include <bits/stdc++.h>
using namespace std;

/**
 * @brief The question asks us to maximize the number of ones. I misunderstood it first and thought that we only need to make the number of
 *        ones > number of zeros but accn to the question, we have to maximize the number of ones.
 *         In order to do that, we know that when we flip 0s, we will get 1s and when we flip 1s, we get 0s. Thus we need to find a subarray
 *        where number of 0s is much greater than 1s and such that this subarray will yield maximum 1s. This feels like maximum subarray sum
 *        Which directs us to kadanes. But, how do we apply kadanes here. That's simple, we replace 0s with +1s and 1s with -1s because we
 *        need 0s so that after flipping, they give us 1s. Therefore, 0s have +1 and 1s have -1. Thus after replacing, we only need to find a
 *        subarray whose sum is maximum... That we can do using kadanes.
 *
 * @param str
 * @return vector<int>
 */
vector<int> flip(string str) {
    int ones=0, zeros=0;
    for(auto u : str){
        if(u=='0') zeros++;
        else ones++;
    }
    if(zeros == 0) return {};
    else{
        vector <int> arr(str.size());
        for(int i = 0; i<str.size(); i++){
            if(str[i]=='0') arr[i] = 1;
            else arr[i]=-1;
        }
        int l=0,r=0;
        int sum_till_now=0, max_sum=INT_MIN;
        vector <int> res;
        for(int i = 0; i<arr.size(); i++){
            sum_till_now += arr[i];
            if(sum_till_now > max_sum) max_sum = sum_till_now, res = {l+1,i+1};
            if(sum_till_now<0) sum_till_now = 0,l=i+1;
        }
        return res;
    }
    return {};
}
