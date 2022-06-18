#include<bits/stdc++.h>
using namespace std;

/**
  @brief    This is an important concept of trees which i relised recently. To serialize a given tree, i used , to seperate two 
            nodes and # to denote null pointer, rest are values. So, doing the recursion, we just return string(val) + left + right

            Now, serialization wasn't that difficult. A little hard part was deserialization. But it isnt that difficult. We just need
            to change the string val in int and then move left and right. So, our base case will be if we have # at first place, we 
            know its EndPoint. So, delete that part from string and return NULL. If its a value, we run a loop to find it, and then
            remove that part from data and pass the new data to the function. 
  
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val)+','+ serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return fun_deserial(data);
    }
protected:    
    TreeNode* fun_deserial(string &data){
        if(data[0]=='#'){
            if(data.size()>2) data = data.substr(2,data.size()-2);
            else data = "";
            return NULL;
        }
        
        // End stops after retrieving a number from data string
        int val, end = 0;
        for(end = 0; end<data.size() and data[end]!=','; end++){}
        
        val = stoi(data.substr(0,end));
        //updated data substring(reference tha, to dikkat bhi nhi :) )
        data = data.substr(end+1,data.size()-end);
        
        // Creating a node, with left and right deserialized
        TreeNode* node = new TreeNode(val);
        node->left = fun_deserial(data);
        node->right = fun_deserial(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));