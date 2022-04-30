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
    Approach : This code works in O(N^2) time but there is another algorithm, known as *MANACHER'S* algorithm to print LPSubstring in O(N).
               Since that algo is way too hard to catch, that's why, i wrote this code in simple brute force. 
                    - A glimpse of ManACher :: In Manacher's algo, we have to take a mirror in the string and check on its left and right
                     sides, whether the characters are matching or not. If they keep on matching, we keep on increasing the lengths of pal
                     indrome centered at that character. For more better understanding : https://www.youtube.com/watch?v=06QIlUBLTz4

               This code simply runs two loops, one from the starting till the end, another from end till i (starting loop variable)
               Whenever we encounter two matching characters from first and last loop, we take that substring, check if it is palindrome or not, 
               compare it with our current palindromic substring, and if it is greater, then update current palindrome with it. At last
               we see if palindrome has been updated or not. If it has length == 0, we return first character, else return palindrome.
               We return first character as single character is always palindrome. 

               --> Same work is done with DP and that too has a xomplexity of O(N^2)
*/

string lpsubstr(string s){

    if(s.length() == 1)
        return s;
    
    // The string that we will return finally
    string lps = "";

    // One loop from starting and another from end
    for(int i = 0; i<s.length(); i++){
        for(int j = s.length()-1; j>=i; j--){
            // If characters match and length of this substr is greater than current LPS j-i (+1) because j and i are indices from 0
            if(s[i] == s[j] && j-i+1 > lps.length()){
                // Check whether this current substring is palindrome or not by comparing it with its reverse
                string temp = s.substr(i, j-i+1);
                string rev = temp;
                reverse(rev.begin(), rev.end());
                
                if(temp == rev)
                    lps = temp;
            }
        }
    }

    if(lps.length() == 0)
        return lps = s[0];
    
    return lps;
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"lOngest Palindromic SubString is : "<<lpsubstr(s)<<"\n";
}