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
    
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        
        int left = 0, right = 0;
        left = dfs(root->left);
        right = dfs(root->right);
        
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        // Along with checking the heights we have to check the remaining substrees as well
        if(abs(dfs(root->left) - dfs(root->right)) <= 1 and isBalanced(root->left) and isBalanced(root->right))
            return true;
        return false;
    }
};