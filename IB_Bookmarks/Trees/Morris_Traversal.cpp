#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Morris traversal is used to find the inorder/preorder/postorder in just O(n) time and [O(1) space complexity]<- special.
            So the basic idea is to maintain a bridge like bond which can help us to get back and get up. Lets understand this much
            better. So when we go on the left subtree of a node, we go to the rightmost child of left subtree and make a connection
            of that child with current node. Lets say, node is current node, left is leftnode and right is rightmost node of left
            subtree. So we make a connection of right and node by pointing right->right = node. This way, we can hop up to node
            without maintaining any parent array.
            Now the basic idea is that we fill all the right nodes and whenever we get a left child as empty, we push that in
            array. And if at any moment, our rightmost child of left subtree points to the same node which we are standing at,
            that means we are repeating, thus we break that node and move to the right now.
 */

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                // If we have a left subtree, we go to the rightmost node of left tree and point its right to current node.
                TreeNode* temp = curr->left;
                // IF by any chance, that right has already been threaded to current node, and temp->right == curr
                // Then we push that current node to array and now we move to right, else we'd have threaded that node to curr.
                while(temp->right and temp->right!=curr)
                    temp = temp->right;

                if(temp->right==NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    // Here we are removing the thread so that tree structure is not altered
                    temp->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{
                // If left child does not exist.
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};