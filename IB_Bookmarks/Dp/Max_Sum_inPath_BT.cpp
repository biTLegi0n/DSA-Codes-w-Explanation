#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this problem, we actually need to find the path with maximum sum. Now what troubled me is that we can start from
            any node and end at any node. So, that thing basically made me think to maintain a vector that stores the path and
            various other approaches. All of them were wrong.
            The fact that we are at a node, and maximum path, if exists throught that node, could be
                - That node itself
                - On the left of that node
                - On the right of that node
                - On both, the left and the right of that node
            The maximum out of above four for every node will be our answer.
            Note that from recursion, we return val + max(left,right), ie, we will return the best answer possible for one node
            and not for the whole problem. For the whole problem, ans is computed with above 4 conditions, for a node, its just
            the max from left or right.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans = INT_MIN;
int fun(TreeNode* root){
    if(!root) return 0;

    int l = fun(root->left);
    int r = fun(root->right);

    int val=root->val+max(l,r);
    ans=max(ans,max(val,max(root->val,l+root->val+r)));
    return val;
}
int maxPathSum(TreeNode* A) {
    ans = INT_MIN;
    fun(A);
    return ans;
}
