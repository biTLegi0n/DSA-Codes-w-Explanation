#include <bits/stdc++.h>
using namespace std;

/**
   @brief   https://www.youtube.com/watch?v=W9SIlE2jhBQ
            In this problem, finding all the permutations was not a good approach. Instead, we used some maths. We find the
            number of permutations starting from a particular number, which are fact[n-1].
            The basic idea is to observe the fact that if we fix a number at each position(for ex, if we have 4 digits, _ _ _ _)
            we set a number at first digit, then we move forward, and update k, and set that digit and so on.
            We need to observe the fact that only (n-1)! permutations starts from a single digit. I mean, if we have 4 digits,
            a total of 4! permutations can be formed. We will have 3! permutations startring from 1, 3! starting from 2, 
            3! from 3 and 3! from 4, and combined they will be 4*3! = 4!.
            That is why, we do k/(n-1)! => we find the block where our permutation might lie. Now after this, we update the k,
            we add the possible digit there, and the problem reduces to a different n and a different k.  

 */

vector <int> fact(10);

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr(n);

        // We precompute all the factorials coz we are going to need it. 
        fact[0]=1, fact[1] = 1;
        factorial(n);

        // fROM this array, we will be selecting the digits of permutation.
        for(int i = 1; i<=n; i++) arr[i-1] = i;

        return fun(n,k,arr,"");
    }
protected:
    int factorial(int n){
        if(n==0 or n==1) return 1;
        return fact[n] = factorial(n-1)*n;
    }

    string fun(int n, int k, vector <int>&arr,string res){
        if(n==0) return res;
        if(arr.size()==1){
            res.append(to_string(arr[0]));
            return res;
        }

        // number of blocks we discarded
        int tk = k/fact[n-1];
        // This is a boundary case. If it is divisible, we need to subtract the tk index of blocks. 
        if(k%fact[n-1] == 0) tk--;
        // we update k as number of blocks discarded,tk multiplied by the total number of elements in each block.
        k = k-fact[n-1]*tk;
        res.append(to_string(arr[tk]));

        arr.erase(arr.begin()+tk);

        return fun(n-1,k,arr,res);
    }
};