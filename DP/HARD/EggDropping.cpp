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
    Approach : This problem has a simple brute force approach but that has a complexity of O(N*K^2) which is really BAD. Also
               if we do this in normal MCM method, then also we have the same complexity.
               Therefore, we approach this problem using the first striked method, BInary Search, with the touch of its brute force
               :: What we are doing different from brute force is that we are checking in middle of a section. If the egg breaks at 
                  that mid, then we check on the remaining DOWNWARDS floors, else we check on the remaining UPWARDS floors. 
               :: We are maintaining two variables namely LEFT & RIGHT, Left -> dropped egg was broken and now we see down
                  RIGHT -> dropped egg survived and we need to see up. 
               :: Also our while loop decides the sections to search for the floor. We update 'l' and 'r' as if left < right
                  we update l -> mid+1 because we want maximum and right is greater than left, thus we move to the section of more
                  so we move our left to upper section, above than mid
                  similiarly, if left > right, we move our 'h' to lower section, h -> mid-1.
            
            -> Finally, we update our 'ans' and 'dp' and return them 
        #$ -> Complexity of this algo is O(KNlogN)
        (.) https://www.youtube.com/watch?v=uBhSIKLlvdk -> for more approaches .
*/

int dp[1005][1005];
int eggdrops(int floors, int eggs){
    // BC#1 : If only 1 egg, then in worst case, we need to try with all n floors
    if(eggs == 1)
        return floors;
    // BC#2 : If number of floors is 0 or 1, then we would not have many options and only try on those floors
    if(floors == 0 || floors == 1)
        return floors;
    
    if(dp[eggs][floors] != -1)
        return dp[eggs][floors];

    // Keep in mind, declare ans locally only. Dont declare it globally, or else it gives WA. Reasons unknown   
    int ans = INT_MAX;
    int low = 0, high = floors;
    // REMEMBER : '<='
    while(low <= high){
        int mid = (low + high)/2;
        int left = eggdrops(mid-1, eggs-1);
        int right = eggdrops(floors-mid, eggs);
        if(left < right)
            low = mid + 1;
        else
            high = mid-1;
            
        int count = 1 + max(left, right);
        ans = min(ans, count);
    }
    return dp[eggs][floors] = ans;
}

int main()
{
    int floors, eggs;

    memset(dp, -1, sizeof(dp));

    cout<<"Enter the number of floors and eggs : ";
    cin>>floors>>eggs;
    cout<<"Minimum number of moves for the critical floor is : "<<eggdrops(floors, eggs)<<"\n";
}