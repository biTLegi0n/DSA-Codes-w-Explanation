#include <bits/stdc++.h>
using namespace std;

/**
  @brief    I wasted a lot of time in this problem trying to solve it using recursion but it demands BFS. Now it was a simple
            observation. Since we are asked to find the maximum time it takes to reach the farthest node from a given node.
            And also, all nodes at a distance k, takes k seconds to burn, i repeat all nodes at distance k. This was it to
            claim that this question demands BFS. Therefore, in such question, where we have something like, many nodes at a
            given level, or time, we use BFS. Here, we have to start from any given random node. From that node, in the base
            tree, we can only go left and right, but the tree will burn in each direction, therefore, we also need to have
            a way to go up. So, we hashed the parent of each node. We can do this using either dfs or bfs. I did bfs.
            So we hash the parents of each node, and in the second bfs, we move to each direction, maintaing a visited map
            so that, we dont fall in an infinite loop.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Since we are burning all the nodes at a given length at one time, therefore, bfs is suited here
int solve(TreeNode* A, int B) {
    TreeNode* start;
    queue <TreeNode*> q;
    q.push(A);
    unordered_map <TreeNode*,TreeNode*> par;
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if(!node) continue;
        if(node->val==B) start = node;

        par[node->left] = node;
        par[node->right] = node;

        q.push(node->left);
        q.push(node->right);
    }

    queue <pair<TreeNode*,int>> q1;
    int ans = 0;
    q1.push({start,0});
    unordered_map <TreeNode*,bool> visited;

    while(!q1.empty()){
        TreeNode* node = q1.front().first;
        int t = q1.front().second;
        q1.pop();

        if(visited.find(node)!=visited.end()) continue;
        if(!node) continue;

        ans = max(ans,t);

        visited[node] = true;

        q1.push({node->left,t+1});
        q1.push({node->right,t+1});
        q1.push({par[node],t+1});
    }
    return ans;
}
