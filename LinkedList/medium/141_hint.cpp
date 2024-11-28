/*********************************************
 * When the slow pointer entered the cycle,
 * it stepped on index 1. Assume the fast was stepping 
 * on index k at the same time. And the size of the 
 * cycle is n. 
 * After s steps, the two pointers met,
 * the slow pointer is on the index (1 + s),
 * while the fast pointer is on the index (k + 2s).
 * Then (k + 2s) - (1 + s) = s + (k - 1) should be evenly divided 
 * by n. 
 * The smallest value for s to fulfill the equator is (n - k + 1).
 ****************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast ->  next -> next;
        if(slow == fast) return true;
    }
    return false;
}
