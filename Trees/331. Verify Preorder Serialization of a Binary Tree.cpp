#include <bits/stdc++.h>
using namespace std;

/**
  @brief    Was not able to think of anything in this question. My mind was repetidely thinking of DFS and BFS queue based
            approaches but nah! IT was simple and straight. If i take a node, it is sure to have two child nodes. Now since we
            have two child nodes, we check if next element is a number of #. If it is a number, we reduce one child and add two
            saying that we place this node on that empty space and add its two children. We keep doing so. If at any point of time
            we have child<0, that means we are out of nodes thus we return false.

 */

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector <string> arr;
        int start = 0;
        for(int i = 0; i<preorder.size(); i++){
            if(preorder[i]==',') arr.push_back((preorder.substr(start,i-start)));
            start = i;
        }
        arr.push_back((preorder.substr(start,preorder.size()-start)));

        int child = 1;
        for(int i = 0; i<arr.size(); i++){
            child--;
            if(child<0) return false;

            if(arr[i]!="#") child+=2;
        }
        return child==0;
    }
};