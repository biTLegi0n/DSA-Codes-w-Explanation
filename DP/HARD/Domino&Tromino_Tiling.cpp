#include <bits/stdc++.h>
using namespace std;

/**
  @n Note   This is for a 2xN board. 
  @brief    This question was not at all hard. It just had some observation. Like, we see that for n=1, we can have only one way,
            For n=2, we can have || or =, ie 2 ways. Now, for n=3, tromino tiles come in picture, and thus, number of ways 
            rises to 5. for n=4, we can see that to all the domnino and tromino combinations of last n, ie n-1, we can add domino
            tiles and can raise the number twice of that + we can also add some tromino tiles to n-3 combinations. We add tromino
            tiles twice to that, therefore, their length will be 3. And thats the reason we are going back by 3. 
  
  --------------------------------------------------------------------------------------------------------------------------------------

  @brief    iF we had a 3xN board and 2x1 tile, then the arrangements could have been different. Then, for 1, the answer would be 0, for 2 however
            it would be 3, as we can see, we can put the horizontal bar up or below those two vertical or beside them too. For, n=3, again
            there would be some empty cell. And from here, we will observe that in a 3xN board, with 2x1 domino tiles, there would always be
            some space left. Therefore, for odd n, the answer will not exist. For even however, we will have two types of choices every time. 
            We can see that with two three tiles vertical and 1 on their base, we can make an L shape and then, with that L shape and its
            horizontal reverse, we can actually fill an even n. So, if we maintain two different arrays for completely even filled dominos
            tiles and space leaving tromino(which we made with 3 verticals and 1 on base), we can form something in our question. 
            We can see the relation, dp[i] = A[i-2] + 2*B[i-1]. Why A[i-2]? That is because we will be putting three bars horizontally
            to fill a new shape, and why B[i-1], well, thats because we will put one bar horizontally, to fill the empty gap, and another 
            vertically, to fill the space left. This leads to adding only 1 length in the shape overall, therefore B[i-1]. 
            But after this, we will have to update B[i] with A[i-1] + B[i-2]. Why so? Well, we can see that after performing the last operation, 
            and filling the cells upto n, we can now add one vertical bar at the end of domino(perfectly filled) to create a tromino shape or 
            we can actually add 3 horizontal bars to previous tromino shape to extend a new one. 3 horizontal means, going back in length by 2. 
 */

// For first
class Solution {
public:
    int mod = 1000000007;
    int numTilings(int n) {
        vector <long long> dp(1002,0);
        dp[1] = 1, dp[2] = 2, dp[3]=5;
        for(int i = 4; i<=n; i++){
            dp[i] = ((2*dp[i-1])+dp[i-3])%mod;
        }
        return dp[n]%mod;
    }
};


// For second   
int solve(int n) {
    if(n%2) return 0;

    vector<long long> a(n+1,0), b(n+1,0);
    int mod = 1000000007;

    a[0] = 1, b[1] = 1;
    a[1] = 0, b[0] = 0;
    for(int i = 2; i<=n; i++){
        a[i] = (a[i-2]%mod + 2*b[i-1]%mod)%mod;
        b[i] = (a[i-1]%mod + b[i-2]%mod)%mod;
    }
    return a[n]%mod;
}
