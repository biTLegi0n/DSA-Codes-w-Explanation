#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This wasn't that difficult than inorder and preorder. In preorder, we had the root in front, here we have it at the
            back Thatsall.!!! Now, since we have the root at the back all the time, therefore, this time, the last root will be
            pointing to the right child/node and thus for left root, we have to make a jump of "number of elements in the right
            subtree". This is the same jump that we make for right, in preorder. That's the only change in this and that code.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return fun(0,inorder.size()-1,inorder.size()-1,postorder,inorder);
    }
protected:
    TreeNode* fun(int l, int r, int idx, vector <int>&post, vector <int>&in){
        if(l>r or idx<0) return NULL;

        int pos = -1;
        TreeNode* root;
        for(int i = l; i<=r; i++){
            if(in[i] == post[idx]){
                root = new TreeNode(in[i]);
                pos = i;
                break;
            }
        }

        root->left = fun(l,pos-1,idx-(r-pos)-1,post,in);
        root->right = fun(pos+1,r,idx-1,post,in);
        return root;
    }
};