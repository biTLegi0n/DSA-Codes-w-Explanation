#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
    First, we check if our string starts from '0' (or) has numbers like '30', '40', .... (or) has two or more consecutive '00'. 
    In that case, there is no message because these substrings has no meaning as per our definition. 
    After that, we move the index in two ways : 
        1. Moving index by 1, which we always move, because 1 characters will always have a meaning except if it is zero
        2. Moving index by 2, which we check if current index has '1' or '2' and index+1 has characters <= 6, then we can have a 
           meaning of two characters.
    
    Finally, we add these two answers. 
*/

map <int, int> dp;

int count_encodings(string str, int index){
    if(str[index] == '0')
        return dp[index] = 0;
        
    if(index >= str.length()-1)
        return dp[index] = 1;
    
    
    if(dp.find(index) != dp.end())
    return dp[index];

    int one = count_encodings(str, index+1);
    if(index < str.length()-1 and (str[index] == '1' or str[index] == '2' and str[index+1] <= '6'))
    one += count_encodings(str, index + 2);
    
    return dp[index] = one; 
}

int numDecodings(string s) {
    int flag = 1;
    if(s[0] == '0')
        return 0;
    else{
        for(int i = 0; i<s.length()-1; i++){
            if(s[i]=='0' and s[i+1] == '0'){
                flag = -1;
                break;
            }
            if(s[i] > '2' and s[i+1] == '0'){
                flag == -1;
                break;
            }
        }
    }
    if(flag == -1)
        return 0;
    else
        return count_encodings(s, 0);
}

int main(){
    string s;
    cin>>s;
    cout<<numDecodings(s);
}