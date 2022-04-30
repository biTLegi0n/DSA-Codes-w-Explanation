#include<bits/stdc++.h>
#define vi vector <int>
#define vl vector <long long>
#define vc vector <char>
#define vp vector <pair <int, int> >
#define INF INT_MAX
#define MIN INT_MIN
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

// A memory efficient way of storing dp elements and can be used in case of memoization. WE need to create a key, mainly string as 
// will be shown below.
map <string, bool> dp;
 /*
        In this problem, I first approached with LCS, but later found out that it can't be done in that way.
    As we can see from the code below, we have to consider every possible case scenerio. We made two choices as usual. 
    1. If the current character of s1 == current character of s3, we consider it a part of s3 for now, and move ahead. 
        We keep on finding the answer by considering the current character as the correct character. for eg, (aa & ab) with (aaba), 
        now when we come to second character, we first compare it with 'a' of first string and then keep on finding the answer 
        from this choice. We know that by considering this 'a' as part of s1, we wont get the answer. 
        So we then consider this 'a' as part of second string. Recursively call the function again, and get the result.
    2. If the current character of s2 == current character of s3, we consider it as a part of s3 and will get the result
        by repeating the steps. 
    
    -> We also consider the cases that if s1 has been traversed fully, we check the character of s2 with s3. If we get a mismatch, 
    we directly return false, because as per question, (s3 = s1 + s2), and if s1 has been found completely then the only substring 
    left is s2, and if it mismatches with what we have, then we dont need to check any further. We get false.
    Finally, we store the answer as (first_call) or (second_call), if we get TRUE from any of it, we store it in map.
*/
bool interleaving(string s1, string s2, string s3, int n1, int n2, int n3, int p1, int p2, int p3){
    
    string key = to_string(p1) + '*' + to_string(p2) + '*' + to_string(p3);

    if(dp.find(key) != dp.end())
        return dp[key];
    
    // Base Cases
    // if s3 has been fully traversed, we check whether s1 and s2 has been traversed or not. If not, then s3 can't be interleaving
    if(p3 == n3)
        return dp[key] = (p1 == n1 && p2 == n2) ? true : false;
    // If s1 has been fully traversed and we find that current s3 character is not matching with current s2 character, then s3 cant' be itl
    if(p1 == n1)
    // Writing in conditional statements looks sexy :)
        return dp[key] = (s2[p2] == s3[p3]) ? interleaving(s1, s2, s3, n1, n2, n3, p1, p2+1, p3+1) : false;
    // If s2 has been fully traversed and we find that current s3 character is not matching with current s1 character, then s3 cant' be itl    
    if(p2 == n2){
        if(s1[p1] == s3[p3])
            return dp[key] = interleaving(s1, s2, s3, n1, n2, n3, p1+1, p2, p3+1);
        else
            return dp[key] = false;
    }

    // Choices
    bool choose_s1 = false, choose_s2 = false;
    if(s1[p1] == s3[p3])
        choose_s1 = interleaving(s1, s2, s3, n1, n2, n3, p1+1, p2, p3+1);
    if(s2[p2] == s3[p3])
        choose_s2 = interleaving(s1, s2, s3, n1, n2, n3, p1, p2+1, p3+1);
    
    return dp[key] = choose_s1 or choose_s2;
}

int main()
{
    string s1, s2, s3;
    cout<<"Enter the two strings : ";
    cin>>s1>>s2;
    cout<<"Enter the string to be checked for interleaving string : ";
    cin>>s3;

    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    
    if(n1 + n2 != n3)
        cout<<s3<<" is not an interleaving string\n";
    else{
        if(interleaving(s1, s2, s3, n1, n2, n3, 0, 0, 0))
            cout<<s3<<" is an interleaving string\n";
        else    
            cout<<s3<<" is not an interleaving string\n";
    }
}