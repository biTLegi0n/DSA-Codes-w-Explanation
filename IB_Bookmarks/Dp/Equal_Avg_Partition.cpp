#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this question, since we need to return partitions whose average are equal, we dont have a direct approach.
            So, we proceed with the fact that equal avg means S1/N1 = S2/N2 and S1+ S2 = S and N1+N2 = N, therefore
            we can write S1/N1 = S-S1/(N-N1). Cross multiply and we get, S1 = (S*N1)/N. So, we basically need to find
            whether there exits N1 elements such that their sum is S*N1/N. And in order to check the validity of this sum
            we say that is S*N1 is divisible by N, only then the sum is possible because we only have integers in our array
            so their sum has to be an integer. Thus, S*N1 has to be divisible by N.
            - We run a loop from 1 to n-1, that number of elements in a partition, and check for validity of each N1. if we
            get a valid N1, we then proceed to find the subset whose sum is S*N1/N. We do this step using backtracking and once
            we have one subset, we can easily accumulate the other subset from the array.

 */

bool check(int ind, int sum, int element, vector<int>&A,
            vector<vector<vector<bool>>> &dp,
            vector<int> &res)
{
    if(element == 0) return (sum==0);
    if(ind>=A.size()) return false;

    if(dp[ind][sum][element] == false)
        return false;

    if(A[ind]<=sum) {
        res.push_back(A[ind]);
        if(check(ind+1, sum - A[ind], element - 1, A, dp, res))
            return dp[ind][sum][element] = true;
        res.pop_back();
    }

    if(check(ind+1, sum, element, A, dp, res))
        return dp[ind][sum][element] = true;

    return dp[ind][sum][element] = false;
}
int main() {
	vector<int> A = {1, 2, 3, 4, 5, 6};
	int n = 6;

	int sum = 0;
	for(auto it:A) sum += it;

    vector<vector<vector<bool>>>dp(n, vector<vector<bool>>(sum+1, vector<bool>(n, true)));


    for(int i = 1;i<=n-1;i++)
    {
        if( (sum * i) % n == 0) {
            int ss = i * sum;
            ss /= n;

            vector<int>res;

            if(check(0, ss, i, A, dp, res)) {
                for(auto it:res)
                    cout << it << " ";
                // self code can be written for finding
                // the second partition
                return 0;
            }
        }
    }

    cout << -1;

}