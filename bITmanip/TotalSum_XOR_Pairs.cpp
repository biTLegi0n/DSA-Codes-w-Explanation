/**
 * @file TotalSum_XOR_Pairs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * In this problem, we need to calculate the total sum of all the unordered XOR pairs. Ex. [5,9,7,6], we need to calculate 5^9 + 5^7 
 * + 5^6 + 9^7 + 9^6 + 7^6 => 47.
 * To do so, We count the total number of set bits at ith position and then do count_at_ith_pos * (2^i). Add this for all the counts.
 * we will have our ans.
 */

#include<bits/stdc++.h>
#define vi vector <int>
#define vl vector <long long>
#define vc vector <char>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    int res = 0;

    for(int i = 0; i<31; i++){
        int count0 = 0, count1 = 0;
        for(int j = 0; j<n; j++){
            if(arr[j]&(1<<i))
                count1++;
            else    
                count0++;
        }

        int total_pairs = count1*count0;   // (Since we need to find the total number of pairs here.)

        res += total_pairs*(1<<i);
    }
    cout<<res<<"\n";
}