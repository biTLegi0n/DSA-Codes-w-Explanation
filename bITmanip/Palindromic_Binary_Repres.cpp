// For more help... See the photos in this folder also the link https://www.youtube.com/watch?v=QYoWR8hDCyQ

/**
 * @file Palindromic_Binary_Repres.cpp
 * @author Rajat Mehra (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 
 We need to observe the pattern of palindromes ie. 1 2 2 4 4 8 8 ..... Accordingly, we keep our count, if it exceeds A, then 
 hop back to the last and then we get the offset. Offset means that if in a group, at which position we have our current Ath element
 Then we do OR operations and find out that number at that position. At last, we wil reverse the portion (half of actual) which 
 makes palindromes.

 */

#include<bits/stdc++.h>
using namespace std;

int reverse(int num){
    vector <int> pos;
    int i = 0;
    while(num>0){
        if(num&1)
            pos.push_back(1);
        else
            pos.push_back(0);
        
        num = num>>1;
        i++;
    }
    // for(auto u : pos)
    //     cout<<u;
    // cout<<"\n";
    int rev = 0;
    i = 0;
    int n = pos.size();
    for(i = 0; i<n; i++){
        rev += (1<<i)*pos[n-i-1];
        // cout<<"ans after adding for "<<i<<" bit, is "<<rev<<"\n";
    }
    return rev;
}

int solve(int A) {
    int count = 0;
    int len = 0, offset;
    while(count < A){
        len++;
        count += (1<<(len-1)/2);
    }
    
    count -= (1<<(len-1)/2);
    offset = A - count - 1;
    // cout<<"Count is "<<count<<" with offset "<<offset<<" and len : "<<len<<"\n";

    int ans = 1<<len-1;
    ans = ans | offset<<(len/2);
    
    // cout<<"ans till now is : "<<ans<<"\n";
    
    int temp = ans>>(len/2);
    int rev = reverse(temp);
    // cout<<"Rev is "<<rev<<"\n";
    ans |= rev;
    return ans;
};
