#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left = NULL, *right = NULL;
};

/**
 * @brief Here we have to print the nodes diagonally, so we observe the graph as tilted level order and with that we see that
 *        the nodes lying in a diagonal are at same level, thus keep their dvalue same, and of the other side, increase by 1
 *        ie if diagonals are towards right, keep the dvalue of right nodes same and while going left, increase it by 1
 */

map <int, vector <int>> mp;

void dfs(TreeNode* root, int d){
    mp[d].push_back(root->val);
    
    if(root->left)
        dfs(root->left, d+1);
    if(root->right)
        dfs(root->right, d);
}
vector<int> solve(TreeNode* root) {
    mp.clear();
    vector <int> ans;
    if(!root)
        return ans;
    
    dfs(root,0);
    
    for(auto u : mp){
        for(auto v : u.second)
            ans.push_back(v);
    }
    return ans;
}