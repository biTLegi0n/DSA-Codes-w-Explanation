/**
 *
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
 *
 * A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
 * The path sum of a path is the sum of the node's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 *
 *
 * SOLUTION:
 * In order to solve this, we had to consider all the possible cases from a node. those are
 * 1. Whether to go left or right from this node
 * 2. Whether to pick the subtree from this node
 * 3. OR, whether stop here.
 *
 * So, considering a subtree from particular node would've meant that we won't be able to get back to its parent node with a answer value.
 * Hence, we need to keep a track of maximam path sum of this subtree.
 * IF, we are not considering this subtree, then we will have to find the maximum path sum from its left or right child, and compare it with
 * current node value + max(left,right) or current node value(If we are retreating from current node and don't wish to go further.)
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int dfs(TreeNode* root, unordered_map <TreeNode*,int>&dp, unordered_map <TreeNode*,int>&startwith){
        if(!root) return 0;

        int left = dfs(root->left,dp,startwith), right = dfs(root->right,dp,startwith);
        dp[root] = max(root->val,root->val+max(left,right));
        startwith[root] = root->val+left+right;
        return dp[root];
    }

    int maxPathSum(TreeNode* root) {
        unordered_map <TreeNode*, int> dp, startwith;
        int ans = dfs(root,dp,startwith);
        for(auto u:startwith) ans = max(ans,u.second);
        for(auto u:dp) ans = max(ans,u.second);
        return ans;
    }
};
