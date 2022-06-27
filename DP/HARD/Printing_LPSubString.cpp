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
                There is a way to do this with dp as well. That is like, if we have a matching character, we check if the inner part between
                those two characters is also matching or not. That we we forrm the dp. One loop start from starting and another from back. 

                Here, this approach is algorithmic. We are not using any space here, and its purely O(n*n) with just two pointers each time. 
                The code is self explanatory. We loop through the string, and at each character, we form two cases 
                    1. If this character is the mid character of a odd length string
                    2. If this character is the mid character of a even length string.   
                If it is odd length, we start the two pointers from left and right of that character and move in both directions untill the 
                characters are matching
                If it is even length, we start from the same character and one right character and move untill the characters are matching. 
*/

class Solution{   
public:
    string longestPalindrome(string str){
        int len = 1;
        string res = "";
        res.push_back(str[0]);
        for(int i = 0; i<str.size(); i++){
            // odd length
            int left = i-1, right=i+1;
            while(left>=0 and right<str.size() and str[left]==str[right]){ 
                if(right-left+1>len) 
                    len = right-left+1, res = str.substr(left,len);
                left--, right++;
            }// even length
            left = i, right = i+1;
            while(left>=0 and right<str.size() and str[left]==str[right]){ 
                if(right-left+1>len) 
                    len = right-left+1, res = str.substr(left,len);
                left--, right++;
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"lOngest Palindromic SubString is : "<<obj.longestPalindrome(s)<<"\n";
}