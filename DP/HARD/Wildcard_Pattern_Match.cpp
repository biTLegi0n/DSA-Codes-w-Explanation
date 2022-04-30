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

/*
    Approach : we as usual, makes two choices but on one condition here. If pattern[j] == '*', then only we make our choices, because
               this '*' could replace one character as well as a series of characters. if we have a '?', then we have no choice at all.
               We just replace it and move ahead. Also, we need to check one thing that if the current characters of both str and pattern
               mismatch and it is not '?', then the answer will be false. So we directly return false from there.
               -> The trick is in its base cases also. We see that if both the string have been traversed, then we return true.
                  if only pattern has been traversed fully, then we can't convert the pattern string in str, thus return false.
                  if only str has been traversed, then we check if we have only '*' in the end of pattern, we can replace all the '*'
                  by NULL and can still have the str, but if we have anything else than that, we return false.
*/

unordered_map <string, bool> dp;

bool wildcard(string str, string pattern, int i, int j, int n, int m){
  /*
    Note: Dont write else betwen the if conditions of base case. That creates problems of executing a base case even when it is not the base case. ie.
    if 'if' is failed then 'else' will execute itself, no matter what.
  */

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
    int k = j;
    while(k < m){
      if(pattern[k] != '*')
        return dp[key] = false;
      k++;
    }
    return dp[key] = true;
  }

  if(dp.find(key) != dp.end())
    return dp[key];

  if(pattern[j] == '*')
    return dp[key] = wildcard(str, pattern, i+1, j, n, m) or wildcard(str, pattern, i, j+1, n, m);
  else
  if(pattern[j] == str[i] or pattern[j] == '?')
    return dp[key] = wildcard(str, pattern, i+1, j+1, n, m);
  else
    return dp[key] = false;
}

int main(){
  string str, pattern;
  cin>>str>>pattern;

  if(wildcard(str, pattern, 0, 0, str.size(), pattern.size()))
    cout<<"true";
  else
    cout<<"false";
}