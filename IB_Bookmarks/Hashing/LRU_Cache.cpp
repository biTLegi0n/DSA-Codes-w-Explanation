#include <bits/stdc++.h>
using namespace std;

/**
   @brief   This question literally took hours of my time. There are two steps in this approach.
            1. Making a data structure that keeps the least recently used key on one side and most recently used key on the
               other. We know that there is nothing better than linked list to do so where we can keep the least recently used
               on one side(here, on head) and most recently used on the other. For the sake of this problem, we will make a
               doubly linked list to store the previous of each node without using any extra space to store them. They will be
               needed when we change most recently used key, where we need to detach that node from its position and add it to
               the last.
            2. Searching that if a node is present in the linked list and if it is not present, then adding it to the linked list
               while making sure that the list size is not greater than the capacity of cache.

            We maintain two maps where map <> mp store the position/address of each key node, so that searching becomes O(1), and
            map <> cache which stores the value of each key.

 */

// WE make doubly linked list node.
struct Node {
    int val;
    Node* prev, *next;
    Node(int x) : val(x),prev(NULL),next(NULL){}
};

unordered_map <int,Node*> mp;
unordered_map <int,int> cache;
Node* head,*last;
int cap;

class LRUCache {
public:
//  Clear all the globals in constructor
    LRUCache(int capacity) {
        mp.clear();
        cache.clear();
        cap = capacity;
        head = NULL, last = NULL;
    }

    int get(int key) {
        // If the key is not present in cache, we simply return -1
        if(cache.find(key)==cache.end()) return -1;

        Node* temp = mp[key];

        // If the key is at last node of list, then we dont have to update the last, because it is already most recently used
        if(temp == last) return cache[key];

        // IF the key is at head, then we update head, add the node to last, and *[update its value in mp]<-important
        if(temp == head){
            head = head->next;
            add_last(key);
            mp[key] = last;
        }
        else{
            // Else we add prev of temp to next of temp and prev of next to previous of temp
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            add_last(key);
            mp[key] = last;
        }
        return cache[key];
    }

    void put(int key, int value) {
        // If the value is already present in the map, then we only need to update its values in both maps based on its current pos
        if(cache.find(key)!=cache.end()){
            Node* temp = mp[key];

            if(temp == last){
                cache[key]=value;
                return;
            }
            if(temp == head){
                head = head->next;
                add_last(key);
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                add_last(key);
            }
            mp[key] = last;
            cache[key] = value;
        }
        // eLse, if the capacity has already reached its max, we erase the head, and add a new node at the last
        else{
            if(cache.size()>=cap){
                mp.erase(head->val);
                cache.erase(head->val);
                head = head->next;
                add_last(key);
                cache[key] = value;
                mp[key] = last;
            }
            else{
                add_last(key);
                cache[key] = value;
                mp[key] = last;
            }
        }
    }
private:
    // This function adds a new node at the end of the list and updates the last(and head also, if it null)
    void add_last(int val){
        Node* temp = new Node(val);
        if(!head) head = temp;
        if(!last) last = temp;
        else{
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */