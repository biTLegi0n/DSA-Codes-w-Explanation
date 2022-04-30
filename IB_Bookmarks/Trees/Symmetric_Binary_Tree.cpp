#include <bits/stdc++.h>
using namespace std;

/**
  @brief    This problem was approached in a different way which complicated this. Therefore, this solution has the
            straightforward approach to this where we store each level in an array and check if it is palindrome or not.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool ispalin(vector <int> &arr){
    for(int i = 0; i<arr.size()/2; i++){
        if(arr[i]!=arr[arr.size()-i-1]) return false;
    }
    return true;
}
int isSymmetric(TreeNode* root) {
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector <int> arr;
        while(n--){
            TreeNode* node = q.front();
            q.pop();
            if(node){ arr.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            else arr.push_back(-1);
        }
        if(!ispalin(arr)) return 0;
    }
    return 1;
}
