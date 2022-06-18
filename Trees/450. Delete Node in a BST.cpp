#include<bits/stdc++.h>
using namespace std;

/**
  @brief    When we delete a node, three cases are possible,
                1. Node has no children - This case is simple. We just need to delete the node and connnect its parent
                2. Node has a children - We connect the child node to parent node and delete the node
                3. Node has 2 children - Here, we either choose maximum from left subtree or minimum from right subtree and swap the 
                                        value of node with that so that the BST is maintained.
  
 */


//  * Definition for a binary tree node.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);    
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};