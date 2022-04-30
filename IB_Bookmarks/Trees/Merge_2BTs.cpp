#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This problem too was very simple and easy if you dont go in any wrong direction. We directly use the same function
            as recursive function and merge the two current nodes and move left and right in both at the same tine. Trees have
            similiar problems which are approached in the same way so think in that same way.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solve(TreeNode* A, TreeNode* B) {
    if(A == NULL)return B;
    if(B == NULL)return A;//two base conditions

    int val1 = A->val , val2 = B->val;
    A->val = val1 + val2;

    A->left = solve(A->left,B->left);
    A->right =solve(A->right,B->right);

    return A;
}