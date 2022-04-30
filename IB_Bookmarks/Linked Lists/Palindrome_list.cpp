#include <bits/stdc++.h>
using namespace std;

// This code is self explanatory

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int lPalin(ListNode* head){
    stack<int> st;

    ListNode * node = head;

    while(head){
        st.push(head->val);
        head = head->next;
    }

    while(node){
        if(node->val != st.top())
            return 0;
        st.pop();
        node = node->next;
    }

    return 1;
}
