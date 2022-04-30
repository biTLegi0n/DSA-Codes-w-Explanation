#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <climits>  // Used for INT_MAX & INT_MIN
#include <algorithm> // for sort and other algorithmic funs
#include <iomanip>  // Used for set precision
#include <cstring>  // for memset
#include <math.h>

using namespace std;

/**
  @brief    In this problem, * replicates its previous character and not any character. This is the only challenge. So, we
            see it like, if the next character is *, then we make the choices regarding the current character. If the current
            character is equal to str1[i], then we can make choices to replicate it or omit it, else we have to omit it. Because
            this character is not equal to the current character of index i. This is the first condition, now in next, we check
            if(two characters are equal or if str2[j]=='.'), in both cases, we move one one pointer in each string. In neither
            of these cases, we return false.

 */

unordered_map <string, bool> dp;

bool RegEx(string str, string pattern, int i, int j, int n, int m){

  string key = str + to_string(i) + to_string(j);

  // base cases
  // Both traversed
  if(i >= n and j >= m)
    return dp[key] = true;
  // pattern traversed
  if(j >= m)
  return dp[key] = false;
  // String traversed
  if(i >= n){
    int k = m-1;
    while(k >= j){
      if(pattern[k] != '*')
        return dp[key] = false;
      k-=2;
    }
    // cout<<"While loop se true\n";
    return dp[key] = true;
  }

  if(dp.find(key) != dp.end())
    return dp[key];

  if(pattern[j+1] == '*'){
      if(pattern[j] == str[i] || pattern[j] == '.')
        return dp[key] = RegEx(str, pattern, i+1, j, n, m) or RegEx(str, pattern, i, j+2, n, m);
      else
      //   cout<<"Before *, no match\n";
      return dp[key] = RegEx(str, pattern, i, j+2, n, m);
  }
  else
  if(pattern[j] == str[i] or pattern[j] == '.')
    return dp[key] = RegEx(str, pattern, i+1, j+1, n, m);
  else
    return dp[key] = false;
}

int main(){
  string str, pattern;
  cin>>str>>pattern;

  if(RegEx(str, pattern, 0, 0, str.size(), pattern.size()))
    cout<<"true";
  else
    cout<<"false";
}