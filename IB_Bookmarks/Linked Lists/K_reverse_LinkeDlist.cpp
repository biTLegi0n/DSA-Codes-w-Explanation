#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   Nothing to explain. Just pure implementation of whats asked in the problem.
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* A, int B) {
    // General case when B is 1, in that case, we have to reverse one element at a time, which literally changes nothing...
    if(B==1) return A;

    // These nodes initialised to reverse the linked list (k nodes at a time)
    ListNode* head = A, *prev = NULL,*curr=head;
    ListNode* root = new ListNode(-1);
    int k=0;
    while(head){
        ListNode* start = head;
        k=0;
        // reversing the k nodes at a time
        while(k<B and head){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
            k++;
        }
        k=1;
        // So if we are at the first block of k nodes, then kth node is set at root
        if(root->val==-1 and root->next==NULL) root->next = prev;

        ListNode* nextend = curr;
        // Then we connect the first node to the next kth node which will be the first node after reversing
        while(k<B and nextend){
            nextend = nextend->next;
            if(nextend->next==NULL) break;
            k++;
        }
        start->next = nextend;
    }
    head = prev;
    return root->next;
}
