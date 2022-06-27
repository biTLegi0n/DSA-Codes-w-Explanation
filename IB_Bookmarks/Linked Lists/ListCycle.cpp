#include<bits/stdc++.h>
using namespace std;

/**
 * @brief   In this problem, we have to use a method, which is known as Slow-Fast pointer method. In this method, we have to
 *          use two pointers, one is slow which moves slowely, one is fast which moves comparatively fast. Now, by slow movement
 *          we mean that slow pointer moves by 1 step and by fast movement, we mean that fast pointer moves by 2 steps.
 *          Now, this problem is divided in two components. One is to detect the cycle in linked list, which can be detected
 *          when slow and fast pointers collide.
 *          Second, is when we actually find the start of the cycle. To do so, when we find the collision, we reset the fast
 *          pointer to start of linked list and keep the slow pointer at the collision. Now, we move both pointers by one step
 *          And when they meet, we find the start. This can be proved. See the photo "ListCycle.png".
 *          S is distance from startnode to collision node and f is total distance travelled, where c is the circumference of circle
 *          nc means we have traversed the cycle n times before finally colliding. 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* A) {
    ListNode* slow = A, *fast = A;
    while(fast){
        slow = slow->next;
        if(fast->next) fast = fast->next->next;
        else break;
        if(slow == fast){
            slow = A;
            while(slow!=fast){
                slow=slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return  NULL;
}
