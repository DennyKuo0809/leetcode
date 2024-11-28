/********************************
 * Refer to the explanation.
 * https://leetcode.com/problems/linked-list-cycle-ii/solutions/44781/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description/
 **********************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    struct ListNode *meet = NULL;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            meet = slow;
            break;
        }
    }
    
    if(!meet) return NULL;
    slow = head;
    while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
