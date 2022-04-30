#include <bits/stdc++.h>
using namespace std;

/**
 * @brief   This problem was really really very nice. Since I was not allowed to do this in O(n*n), where i'd just swap the
 *          larger number with the smaller one, Here, i had to do this in O(nlogn).
 *          To do this in O(nlogn) time and constant space, I used Merge sort. Although we take some space while merging arrays,
 *          but here since we have to merge two linked list, we can just add some links and save up space while doing sorting in
 *          O(nlogn).
 *          1. Division step : The first step in merge sort is to divide the array, each time in half untill we have one element
 *                             in that case, we return the element. To divide the list in half, we use slow-fast pointer method.
 *                             Slow pointer moves 1u while fast moves 2u. Thus, when fast reaches the end, slow reaches the mid
 *                             of list. In this way, we sucessfully divide the list in two, Head-null(we point the prev of slow
 *                             to null so as to make it a seperate list), and slow-end
 *          2. Merge step :    The second step in merge sort is to merge the divided arrays while making sure that we sort them
 *                             while merging. Merging linked lists is easy peasy.
 *
 * @note    Do note that we dont need to make a new list while merging the two divided lists, We can directly link the new list's
 *          node to the current list node. Creating new nodes each time will consume space thus increasing space complexity.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* A, ListNode* B) {
    ListNode* i = A, *j = B;
    ListNode* root = new ListNode(-1), *temp = root;
    while(i and j){
        if(i->val < j->val){
            // ListNode* node = new ListNode(i->val);
            temp->next = i;
            temp = i;
            i=i->next;
        }
        else{
            // ListNode* node = new ListNode(j->val);
            temp->next = j;
            temp = j;
            j=j->next;
        }
    }
    while(i){
        // ListNode* node = new ListNode(i->val);
        temp->next = i;
        temp = i;
        i=i->next;
    }
    while(j){
        // ListNode* node = new ListNode(j->val);
        temp->next = j;
        temp = j;
        j=j->next;
    }
    return root->next;
}

ListNode* sortList(ListNode* A) {
    if(A == NULL or A->next == NULL) return A;

    ListNode *slow = A, *fast = A;
    ListNode* head = slow, *prev = head;;
    while(slow and fast){
        prev = slow;
        slow = slow->next;
        if(fast->next) fast = fast->next->next;
        else break;
    }

    prev->next = NULL;

    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(slow);

    return merge(l1,l2);
}