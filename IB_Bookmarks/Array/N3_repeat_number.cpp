#include<bits/stdc++.h>
using namespace std;

/**
 * @brief
 * https://www.youtube.com/watch?v=WPdjhTryjPE  <-  Solution
 *
 * This question has to be solved in O(n) time and O(1) space. Therefore, i had no idea how to approach this. Then this video came in
 * picture. Now, in this video, what the man showed us is like Moore's voting algorithm. In moore's voting, we learned how to find a number
 * appearing more than n/2 times, here we are asked to check for number appearing more than n/3 times. So basically we can approach like that
 * Now, its not exactly moore's. Here we will have 4 variables instead of 2. Namely they are c1, c2, e1, e2. c1 and c2 will act as count and
 * e1 e2 will store the numbers. Rest can be seen from the below code. Whenever we encounter a number equal to e1, we do c1++, and when we
 * encounter number equal to e2, we do c2++. Now when c1 or c2 is 0, we update e1 and e2. After all, we count c1 and c2, and check which of
 * them is > n/3, and return e1,e2 accordingly...
 *
 * @param arr
 * @return int
 */
int repeatedNumber(const vector<int> &arr) {
    // It is a moore's algorithm like question...
    int c1=0, c2=0,e1=INT_MAX,e2=INT_MAX;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]==e1){
            c1++;
        }
        else
        if(arr[i]==e2)
            c2++;
        else
        if(c1==0){
            e1=arr[i];
            c1++;
        }
        else
        if(c2==0){
            e2=arr[i];
            c2++;
        }
        else
            c1--, c2--;
    }
    c1=0,c2=0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]==e1) c1++;
        else
        if(arr[i]==e2) c2++;
    }
    if(c1>arr.size()/3) return e1;
    if(c2>arr.size()/3) return e2;
    return -1;
}
