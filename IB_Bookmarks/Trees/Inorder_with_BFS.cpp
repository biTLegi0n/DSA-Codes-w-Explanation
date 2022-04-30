#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This was a very good method to find the inorder/preorder or any order of the tree. Here, we use bfs, but with stack
            Since, we have to start from the lowest node on left hand side, we use stack, and go till the very end in left.
            After that, when we end up at the last node pushing all the intermidiates in stack, our root will now point to null
            Thus the second loop ends, and now we reset the root to top of stack, which is the last node we pushed to it, ie,
            leftmost node. We push this node to array, and change the root to root->right, so that, if we have a node to its right,
            we consider that too! After doing so, we go to the right and repeat the same process in the second while loop.
  @note     We do not pass anything in the stack initially thats why we have an extra condition of while("root" or !st.empty)
            This is because if we pass root's value to stack initially, then in the second while loop, it will be passed again
            and that would create a mess.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> inorderTraversal(TreeNode* root) {
    stack <TreeNode*> s;
    vector <int> arr;
    while(root or !s.empty()){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();

        if(!root) continue;

        arr.push_back(root->val);
        root = root->right;
    }
    return arr;
}
