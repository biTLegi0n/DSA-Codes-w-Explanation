#include <bits/stdc++.h>
using namespace std;

/**
  @brief    To solve this question, we have two methods. Now i encountered the problem in Hashing! So One of the methods is
            hashing. And another is altering the linked list itself and then rearranging it to retrieve the original list.
            - [HASHING] : iN this methods, we make a map of nodes itself. We go through the list and for each node, we create
                          an alias node, and then map this list node to this copy node. Now next time, when we go through the
                          list, we map the nodes to their copy nodes and their random nodes to that random's copy node too.
                          The implementation can be seen below. TC - O(n) SC - O(n)
            @note   Do not make the mistake of hasing the values to the nodes, ie making a map of <int,NODE*> because we can
                    have two nodes with same values and then the problem would arise. Therefore, it is suggested to make a map
                    of <node*,node*> so that each node can have a deep copy of itself.


            - [LIST] : iN this method, we first insert a copy of each node between the node and next node. After doing this for
                       all the nodes, we then update the random pts of these middle nodes, and at last step, we retrieve the
                       copy list and the original list.
                       STEP 1 : wE make a copy of the current node, insert this copy between the current node and its next node.
                                Now the list will be some like 1->1(copy)->2->2(copy).......
                       STEP 2 : Now, when we have inserted the nodes in between, we now set the random pointers. To do so, we
                                go to the random pointer of current temp node, and then in the copy node of current temp node,
                                we set the copy node of temp's random node. ie, temp->next->random(copy ka random) = temp->random
                                ->next(random ki copy)
                       STEP 3 : Now, in the last step, we connect all the copy nodes directly and retrieve the original list.
                                Because the original list has to be returend as it is.
                        TC - O(n), SC - O(1)[No extra space]

 */

/*
------------------------------------------------------  HASHING ---------------------------------------------------------
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map <RandomListNode*,RandomListNode*> mp;
    RandomListNode* temp = A;
    while(temp){
        RandomListNode* node = new RandomListNode(temp->label);
        mp[temp] = node;
        temp = temp->next;
    }
    temp = A;
    RandomListNode* root = new RandomListNode(-1);
    RandomListNode* head = root;
    while(temp){
        // cout<<"Current head is "<<head->label<<" and temp is "<<mp[temp]->label<<"\n";
        head->next = mp[temp];
        head = head->next;
        head->random = mp[temp->random];
        temp = temp->next;
    }
    head->next = NULL;
    return root->next;
}
------------------------------------------------------  HASHING ---------------------------------------------------------

*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // I have written a code using maps in IB, that can also be found in my notes.
        if(!head) return NULL;
        Node* temp = head, *next=NULL;

        while(temp){
            Node* newnode = new Node(temp->val);
            next = temp->next;
            temp->next = newnode;
            newnode->next = next;

            temp = next;
        }
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }

        Node* root = head, *temp2 = head->next;
        temp = root;
        root = root->next;
        while(temp and temp2){
            temp->next = temp->next->next;
            if(temp2->next)
                temp2->next = temp2->next->next;
            else
                temp2->next = NULL;

            temp = temp->next;
            temp2 = temp2->next;
        }

        return root;
    }
};