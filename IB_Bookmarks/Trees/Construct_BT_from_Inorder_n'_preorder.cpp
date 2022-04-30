#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This one is still easy that making tree using inorder and postorder. We just need to know how inorder and preorder
            are written. Inorder is [Left->root->right] and preorder is [Root->left->right]. Now this here means that even
            when we are on the right hand side of root, we will first consider the left children and the the parent itself.
            That's what meant by root->left->right, ie, left before right in each side. So that simply reduces this problem
            to a simple recursion where we just need to define two halves for each node.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fun(0,inorder.size(),0,preorder,inorder);
    }
protected:
    TreeNode* fun(int l, int r, int idx, vector <int>&pre, vector <int>&in){
        if(l>r or idx>=pre.size()) return NULL;

        int pos = -1;
        TreeNode* root;
        for(int i = l; i<=r; i++){
            if(in[i] == pre[idx]){
                root = new TreeNode(in[i]);
                pos = i;
                break;
            }
        }

        root->left = fun(l,pos-1,idx+1,pre,in);
        root->right = fun(pos+1,r,idx+(pos-l)+1,pre,in);
        return root;
    }
};