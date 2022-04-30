#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This problem has a very simple logic behind it. Since we are checking the validity of a Binary Seach Tree, therefore,
            it is sure that below each node, on its left, will be nodes which are smaller than it, and on its right will be nodes
            which are greater than it. This is the property we will be using in this appraoch.

            We basically find a next greater element, which is greater than current which denotes the start of right subtree of
            the node with which we are comparing, and after that node, if we find a node which is smaller than the root node, we
            return false. Because after the start of right subtree, we can not have a smaller node.
            The brute force asks us to do this in O(n*n) but an optimal method uses stack.
            We find the next greater element, and after that, if we ever encounter a smaller element than root, we return false.
            Each time, root is top of stack. We keep on pushing in stack untill we have elements less than root, and popping untill
            we have the current element greater than root.

 */

int solve(vector<int> &A) {
    stack <int> st;
    int root = -1;
    for(int i = 0; i<A.size(); i++){
        while(!st.empty() and st.top()<A[i]) root = st.top(), st.pop();
        if(A[i]<root) return 0;
        else st.push(A[i]);
    }
    return 1;
}
