
 struct TreeNode {
 int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map <int, vector <int>> mp;
    /*
    Tried to solve this question using DFS but with DFS, it was difficult. How? Since we have to store 
    the nodes according to their vertical as well as horizontal level, therefore, to deal with this
    horizontal thing, we have to go level order.
    */
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector <vector <int>> ans;
        
        if(!root)
            return ans;
        
        queue <pair <TreeNode*, int> > q;
        q.push({root,0});
        int current = 0;
        vector <int> v;
        while(!q.empty()){
            int len = q.size();
            multiset <pair<int,int>> s;
            // Jitne elements queue me h, unko ek saath process kar rhe h hum
            for(int i = 0; i<len; i++){
                int lev = q.front().second;
                TreeNode* temp = q.front().first;
                q.pop();
                s.insert({lev,temp->val});
                
                if(temp->left)
                    q.push({temp->left,lev-1});
                if(temp->right)
                    q.push({temp->right,lev+1});    
            }
            
            for(auto u : s)
                mp[u.first].push_back(u.second);
        }
        
        for(auto u : mp)
            ans.push_back(u.second);
        
        return ans;
    }
};