#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This problem can be solved by two different methods. One is by using a formula based technique where the formula is
            res[i] = i^(i>>1) and another method is intuitive which is using recursion. Well the explanation to the first method
            is with the code, and for the second one, below.
            - We know that for the base case, if we have n=1, then only two gray codes are possible, ie [0,1]. Now, if we have
            n=2, then gray codes are [00,01,11,10]. One thing to note here is that, if we have gray codes for n=1, we also have
            for n=2, as for n=2, we just add '0' and '1' before the codes of 1. as 0->[0,1] and 1->[0,1]. The only thing that we
            have to take care of is that, if we directly add 0 and 1, before the elements, we end up having 00,01,10,11 where
            01 and 10 have a bit difference of 2. So to handle this, we add 0 directly while we add 1 in reverse fashion. That
            leads us to give 00,01 _ 11,10 which are the correct gray codes. So we do this only. We add 0 to gray code of n-1
            directly while we add 1 to gray codes of n-1 in reverse order.


   @return vector <string>
 */

class Solution {
public:

    //This is a formula based problem.. We have to think of this formula only!
    vector<int> grayCode(int n) {
        vector <int> res(1<<n);

        for(int i = 1; i<(1<<n); i++){
            res[i] = i^(i>>1);
        }
        return res;
    }
};
/*
I try to give a simple proof here. Let's denote i^(i>>1) as f(i). To proof f(i) is the ith gray code, we only need to prove the following statements:

    f(0) = 0
    (i) and f(i+1) only differs in one digit
    f(i) is bijective, e.g. f(i) = f(j) if and only if i = j.

The first one is obvious.

For the second , f(i) ^ f(i+1) = i^(i>>1)^(i+1)^((i+1)>>1) = (i^(i+1)) ^ ((i^(i+1)) >> 1). Let's denote g(i) = i^(i+1), g(i) has the form of 0000111...111. So f(i) ^ f(i+1) = g(i) ^ g(i)>>1 = 00001000...000.

The third part can be proved alike.
*/


//-------------------------------------------------------------------------------------------------------------

vector <string> fun(int n, vector <string>&temp){
    if(n == 1){
        temp.push_back("0"), temp.push_back("1");
        return temp;
    }

    temp = fun(n-1,temp);
    vector <string> arr;
    for(int i = 0; i<temp.size(); i++) arr.push_back("0"+temp[i]);
    for(int i = temp.size()-1; i>=0; i--) arr.push_back("1"+temp[i]);

    return arr;
}
vector<int> grayCode(int n) {
    vector <string> temp;
    vector <string> arr = fun(n,temp);
    vector <int> res;
    for(auto u : arr){
        int num = stoi(u,0,2);
        res.push_back(num);
    }
    return res;
}
