#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN -99999999
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
/*
    Approach : This code is of EXPERT level, in GFG. Well first point to note is that we use map in this question instead of matrix.
        Algo : We follow simple memoization approach in this code. Our base cases are :
                - If the length of two passed strings are not equal, we return 'false' in that case
                - if length is equal to 0, then they are scrambled because empty strings are everything
                - and if they are equal, then also we return 'true'
                    - We can also have an additional BaseCase, which is, we compare both the strings and if the characters in them
                      are not same, then we return false. we check them by sorting them and then direct comparing
              After base cases, we check if the key string which is the combination of given two strings, is present in map or not
              if it is present, we directly return it, else we move ahead to find it.
              In the for loop, we check for all the possibilites, by diving both the strings and making two choices,
                    1. The partitions are not swapped, thus passed accordingly
                    2. The partitions have been swapped, thus first part is now in the last of second string
              We check for both the cases, if they are scrambled for real, one of them returns true, accordingly, if one is swapped
              then second statement, if not swapped then first statement return true.
*/
unordered_map <string, int> dp;

bool areScrambled(string s1, string s2){
    if(s1.length() != s2.length())
        return false;

    int n = s1.length();

    if(n == 0)
        return true;

    if(s1 == s2)
        return true;

    string key = s1 + "_" + s2;

    if(dp.find(key) != dp.end())
        return dp[key];

    for(int i = 1; i<n; i++){
        if(areScrambled(s1.substr(0, i), s2.substr(0, i)) && areScrambled(s1.substr(i, n-i), s2.substr(i, n-i)))
            return dp[key] = true;
        /*
        Below statement says that they have been swapped. 1st substring is starting from 0 and of length i. Now if we claim
        that they are swapped then, the second substring which we send to the function to check whether those two substrings
        are scambled or not, should be of same length, else it would directly return false in both cases. So we need to make
        sure that we send the correct substring in both cases. Therefore, in first, s1.substr(0, i) , s2.substr(n-i, i) ::
            we say that a substring of s1 from 0 (of length i) should be compared with a substring of s2 starting from n-i
            (of length i). NOTE: starting from n-i means i steps back from n(<----) means that portion was swapped and now
            we compare that.
        Similiarly, we do with the second condition, after &&. We say that a substring starting from i of length n-i. (Length
        is n-i because a substring of length i has already cut off from this string, therefore, remaining length is n-i) is compared
        with a substring starting from 0 of length n-i :: AS you can see, length is same, and starting positions are different, which
        tells that they have been swapped :)
        */
        if(areScrambled(s1.substr(0, i), s2.substr(n-i, i)) && areScrambled(s1.substr(i, n-i), s2.substr(0, n-i)))
            return dp[key] = true;
    }
    return dp[key] = false;
}

int main()
{
    dp.clear();

    string s1, s2;
    cout<<"Enter both the strings : ";
    cin>>s1>>s2;
    if(areScrambled(s1, s2))
        cout<<"Given strings are scrambled strings :)\n";
    else
        cout<<"Given strings are not scrambled :(\n";
}