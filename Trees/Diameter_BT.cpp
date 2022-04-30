#include<bits/stdc++.h>
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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->left and !root->right)
          return 0;
     
        height(root);
        return d;
    }
protected:
    int height(TreeNode* root){
        if(!root)
            return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        int temp =  1+max(left,right);
        d = max(d, left+right);
        return temp;
    }
};