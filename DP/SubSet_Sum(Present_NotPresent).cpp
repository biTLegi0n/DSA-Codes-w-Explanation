#include<bits/stdc++.h>
#define vi vector <int>
#define vp vector <pair <int, int> >
#define INF 99999999
#define MIN -99999999
#define pb push_back
#define mp make_pair
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

/*
    Approach : This question is a type of Knapsack problem. We use the same type of formula.
        - in coloumns, we have all the possible sums upto the sum we need.
        - in rows, we have number of elements
    People mostly uses Bitwise OR operator in the formula.

    NOTE: This code only tells us whether there is any subset or not, it doesnot print the subset.


                                    ========================================================  
        There is one more thing to note in this problem, If we are asked to find equal Sum partitions, we can do so by 
        simply finding the subsets having half the sum of array. Let me elaborate, if we have a array whose sum is EVEN
        ( It is important that the array has even sum, because only then we can divide it in two equal partitions), we 
        can divide the sum in two equal parts and then use this code to find whether subsets having the half sum are 
        present or not. if present we return true else return false.
                                    ========================================================

*/
int dp_rec[1005][1005];

/*
    For Recursion : We follow the same approach, i.e going on each element and checking whether to consider it or not
        - we take the max(or bitwise OR operator) to fill the dp array .
        -> For base cases,
            - if we have zero elements left in the array, we have to return 0
            - if we make the sum == 0, then we found the subset
*/
int subset_rec(int n, int sum, int a[]){
    if(n == 0)
        return 0;
    if(sum == 0)
        return 1;
    
    if(dp_rec[n][sum] != -1)
        return dp_rec[n][sum];
    else{
        if(a[n-1] > sum)
            return dp_rec[n][sum] = subset_rec(n-1, sum, a);
        else  
            return dp_rec[n][sum] = max(subset_rec(n-1, sum - a[n-1], a) , subset_rec(n-1, sum, a));
    }
}

/*
    For Tabulation : Same, Shame! 
        -> We initialize the matrix in a way that 
            - dp[0][0] is 1/True (because if we want a sum of 0 with 0 elements, we can have it)
            - dp[0][j] is 0/False (because, we can't have a sum more than 0 with 0 elements in array)
            - dp[i][0] is 1/True (because we can always have a sum of 0, by taking an empty set {} )
        -> if the current element in the array is greater than the current sum, we neglect that element
        -> else, we make a choice. Take the max(or OR) out of the two choices.
                dp_tab[i][j] = max(dp_tab[i-1][j - a[i-1]], dp_tab[i-1][j])     
*/
int subset_tab(int n, int sum, int a[]){
    bool dp_tab[n+1][sum+1];            
    /* The reason we are taking this DP matrix as bool is that int gives segmentation fault at large values, thus, 
    because bool has size of 1 byte, and int has 4*(1 byte) Thus, taking boolean type matrix is a good choice. 
    Whereever you can, you should try to take boolean  */

    /*
        DP is So precise that even wrongly initialization disturbs the whole work
        Thats why we have initialized it outside of nested loops and initialised it in a way such that dp[0][0] = true
    */
    for(int i = 0; i<=n; i++)
        dp_tab[i][0] = true;
    for(int j = 1; j<=sum; j++)
        dp_tab[0][j] = false;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(a[i-1] > j)
                dp_tab[i][j] = dp_tab[i-1][j];
            else    
                dp_tab[i][j] = (dp_tab[i-1][j - a[i-1]] || dp_tab[i-1][j]);
        }
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(dp_tab[i][j])
                cout<<"1";
            else    
                cout<<"0";
        cout<<" ";
        }
    cout<<"\n";
    }
    return dp_tab[n][sum];
}

int main()
{
    int n, sum;
    cin>>n>>sum;
    int a[n];
    for(int i = 0; i<n; i++)
        cin>>a[i];

    memset(dp_rec, -1, sizeof(dp_rec));
    subset_rec(n, sum, a);

    if(dp_rec[n][sum] == 1)
        cout<<"Subset Exists! From Recursion :)\n";
    else
        cout<<"No SubSet Exists! :(\n";
    
    int ans_from_tab = subset_tab(n, sum, a);

    
    if(ans_from_tab == 1)
        cout<<"Subset Exists! From Tabulation :)\n";
    else
        cout<<"No subset Exists! :(\n";
}