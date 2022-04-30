#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <climits>  // Used for INT_MAX & INT_MIN
#include <algorithm> // for sort and other algorithmic funs
#include <iomanip>  // Used for set precision
#include <cstring>  // for memset
#include <math.h>

using namespace std;

int dp[505][505];
/**
 * @brief If we need to find all the sequences of a string, lets say abcd, then they will be
 *                                                  _ (bc) _       ==>  4
 *                                                  _ (bc) d       ==>  4
 *                                                  a (bc) _       ==>  4
 *                                                  a (bc) d       ==>  4
 *        Means that if we have a c1 + (middle part) + c2, then all its subsequences will be subsequences of middle part
 *        + choices made on c1 and c2. Thats what we have done in this problem.
 *
 * Dont feel bad if you are not able to understand this question. There is a reason why i was not able to write its proper
 * explanation here. This contains maths and observations of another level...
 * @param str
 * @param i
 * @param j
 * @return int
 */
int countp(string str, int i, int j){
  if(i>j)
    return dp[i][j] = 0;

  if(i == j)
    return dp[i][j] = 1;
  // https://www.youtube.com/watch?v=YHSjvswCXC8     -> From 15:00

  //If characters match, we consider that as a palindromic subsequence and add one for that
  // This 1 is actually counted for the case where inner substring would be taken empty and only s[i]s[j] would form a subseq.
  if(str[i] == str[j])
    return dp[i][j] = countp(str, i+1, j) + countp(str, i, j-1) + 1;

  /* We substract (i+1, j-1) because this particular portion is repeated. We subtract it from above condition also but the full
     condition is countp(str, i+1, j) + countp(str, i, j-1) - countp(str, i+1, j-1) + countp(str, i+1, j-1) + 1 which ultimately
     forms what we have.
  */
  return dp[i][j] = countp(str, i+1, j) + countp(str, i, j-1) - countp(str, i+1, j-1);
}

int main(){
  string str1;
  cin>>str1;

  memset(dp, -1, sizeof(dp));
  cout<<countp(str1, 0, str1.length()-1);
}