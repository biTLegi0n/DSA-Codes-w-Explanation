#include <bits/stdc++.h>
using namespace std;

/**
  @brief    In this question, we are asked to print the tree in a diagonal way. That task alone isn't that hard because to do
            so, we can just maintain a map and a queue and just pass a level-1 each time we go to the left, but here, in this
            problem, we have a little twist. That is, we need to consider the right children before the left children if they
            are in the same level.
                                         15
                                        /   \
                                       20   11
                                      / \   / \
                                    21  17 /   \
                                          16   23

            Now, in the above graph, lev[0] will have {15,11,23}. Lev[1] = {20,17,16}. Now dont write any algorithm that alter
            this sequence. Note that if we'd have taken queue instead of stack, we would've ended up with having 16 before 17
            since in queue, we push left children before right, and the one pushed before are processed. Therefore, we use stack
            here and since we use stack and push the right first and the left at the end, therefore, first 11 and then 20 will be
            pushed and 20 will be processed first since it is at the top due to which children of 20 will be processed before
            the children of 11. Therefore, we get the order.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> solve(TreeNode* root) {
    map <int,vector<TreeNode*>> mp;
    stack <pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        TreeNode* node = q.top().first;
        int lev = q.top().second;

        q.pop();

        if(!node) continue;

        mp[lev].push_back(node);
        q.push({node->right,lev});
        q.push({node->left,lev+1});
    }

    vector <int> res;
    for(auto u : mp){
        for(auto x : u.second) res.push_back(x->val);
    }

    return res;
}
