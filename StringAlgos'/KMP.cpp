#include<bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vvi vector <vector<int>>
#define vl vector <ll>
#define vvl vector <vector<ll>>
#define vp vector <pair <int, int> >
#define INF 99999999

#define MIN -99999999
#define pb push_back
#define mp make_pair
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

// Pi needs to be this large
int pi[200005];

/**
 * @brief KMP sounds likes some big fat ass problem but its actually pretty small. We need to have knowledge of prefix/pi function and
 * boom! We know KMP. First(assuming you know about pi function), we just need to add the pattern before the string and with a random
 * character which is not in string and pattern, to seperate them. Make a new string which is pattern+(randomChar)+string, and apply
 * prefix function on it. It fills the pi[] and now all we need to do is to check for the value which is equal to the size of pattern.
 *
 * Now, talking about the prefix function. You are given a string s of length n. The prefix function for this string is defined as
 * an array π of length n, where π[i] is the length of the longest proper prefix of the substring s[0…i] which is also a suffix of
 * this substring. A proper prefix of a string is a prefix that is not equal to the string itself. By definition, π[0]=0.
 * For example, prefix function of string "abcabcd" is [0,0,0,1,2,3,0], and prefix function of string "aabaaab" is [0,1,0,1,2,2,3].
 *
 * Now 2 optimization were made to this which were
 *    - the value cannot increase by more than 1. It can decrease and can remain the same or can increase by 1
 *    - if the value pi[i-1] is >0 then when we move ahead, we don't need to compare the whole string again, all we need is to compare the
 *      character added.
 *
 * Finally, the algorithm code is written below. We move back untill we find a character that matches the current one. We do so because
 * we need to find the longest proper prefix.
 *
 * Time Complexity : O(N)
 *
 * @return int
 */
int main()
{
    FAST;

    string pat, str;
    cin>>pat>>str;

    string s = pat+'#'+str;
    // -----------------------------------
    //prefix function
    for(int i = 1; i<s.size();i++){
        int j = pi[i-1];
        while(j>0 and s[i]!=s[j])
            j = pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i] = j;
    }
    // -----------------------------------
    int count = 0;
    for(int i = 0; i<s.size();i++) if(pi[i]==pat.size()) count++;
    cout<<count<<"\n";
}