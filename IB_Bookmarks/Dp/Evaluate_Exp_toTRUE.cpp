#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Well, this is not my code. I copied this one from fatty's id. Now in this problem, we maintain a 3d dp table, that
            stores the dp of i,j(well, i and j are sort of pointers that tell us which part is to be considered) with their fact
            ie whether i,j evaluates to true or not. Since we also have xor, therefore we need to have both for true as well as
            false. In other case, where we dont have xor, we could have simply stored TRUE because we can not make TRUE using
            FALSE with AND & OR. But with XOR, we can thus we store that too!
            Now, we divide the paranthesis between i and j, and evaluate if LEFT coule be True or False, RIGHT could be True or
            False and then we use these to get TRUE according to the operators.

 */

int dp[151][151][2];

int mod = 1e3+3;

int rec(string s, int i, int j, int isTrue){
	if(i > j)
		return false;

    if(i == j){
		if(isTrue == 1)
			return s[i] == 'T';
		else
			return s[i] == 'F';
	}

	if(dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];

	int ans = 0;

    for(int k = i + 1; k < j; k += 2){
		int leftF, leftT, rightT, rightF;

        if(dp[i][k-1][1] == -1)
			leftT = rec(s, i, k-1, 1);
		else
			leftT = dp[i][k-1][1];

		if(dp[k+1][j][1] == -1)
			rightT = rec(s, k + 1, j, 1);
		else
			rightT = dp[k + 1][j][1];

		if (dp[i][k - 1][0] == -1)
			leftF = rec(s, i, k - 1, 0);
		else
			leftF = dp[i][k - 1][0];

		if (dp[k + 1][j][0] == -1)
			rightF = rec(s, k + 1, j, 0);
		else
			rightF = dp[k + 1][j][0];

        if (s[k] == '&'){
			if (isTrue == 1)
				ans = ans % mod + (leftT % mod * rightT % mod);
			else
				ans = ans % mod + (leftF % mod * rightF % mod) % mod + (leftT % mod * rightF % mod) % mod + (leftF % mod * rightT % mod) % mod;
		}
		else if (s[k] == '|'){
			if (isTrue == 1)
				ans = ans % mod + (leftT % mod * rightT % mod) % mod + (leftT % mod * rightF % mod) % mod + (leftF % mod * rightT % mod) % mod;
			else
				ans = ans % mod + (leftF % mod * rightF % mod) % mod;
		}
		else if (s[k] == '^'){
			if (isTrue == 1)
				ans = ans % mod + (leftF % mod * rightT % mod) + (leftT % mod * rightF % mod) % mod;
			else
				ans = ans % mod + (leftT % mod * rightT % mod) % mod + (leftF % mod * rightF % mod) % mod;
		}
		dp[i][j][isTrue] = ans % mod;
	}

    return ans % mod;
}
int cnttrue(string s){
    int n = s.length();

    memset(dp, -1, sizeof(dp));

	return rec(s, 0, n-1, 1);
}
