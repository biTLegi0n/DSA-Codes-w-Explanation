#include<bits/stdc++.h>
using namespace std;

// Just no more words for this shity ques. We only have to compare the substrings between two .dots.

int compare(string num1, string num2){
    int i = 0, j = 0;
    int n=num1.length(), m=num2.length();
    while(num1[i]=='0') i++;
    while(num2[j]=='0') j++;

    num1 = num1.substr(i,n-i);
    num2 = num2.substr(j,m-j);

    if(num1.size()>num2.size()) return 1;
    else
    if(num1.size()<num2.size()) return -1;
    else{
        while(i<num1.size() and j<num2.size()){
            if(num1[i]>num2[i]) return 1;
            else
            if(num1[i]<num2[i]) return -1;
            i++, j++;
        }
    }
    return 0;
}
int compareVersion(string A, string B) {
    int i = 0, j = 0;

    while(1){
        if(i>=A.size() and j>=B.size()) return 0;
        string num1="",num2="";
        while(i<A.size() and A[i]!='.')
            num1.push_back(A[i]), i++;
        while(j<B.size() and B[j]!='.')
            num2.push_back(B[j]), j++;

        if(compare(num1,num2)==1) return 1;
        else
        if(compare(num1,num2)==-1) return -1;
        i++, j++;
     }
     return 0;
}
