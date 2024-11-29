/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if(!(head -> next)) return;
    /* Find the second half of the list */
    struct ListNode *slow = head, *fast = head, *prev = NULL;
    while(fast && fast -> next){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    prev -> next = NULL;

    /* Reverse the second half of the list */
    struct ListNode* tail = NULL;
    struct ListNode *originNext = NULL, *newNext = NULL;
    while(slow){
        if(slow -> next == NULL) tail = slow;
        originNext = slow -> next;
        slow -> next = newNext;
        newNext = slow;
        slow = originNext;
    }

    /* Construct the interleaving list */
    struct ListNode *p1 = head, *p2 = tail;
    struct ListNode *newTail = NULL;
    originNext = NULL;
    while(p1){
        originNext = p1 -> next;
        p1 -> next = p2;
        p2 = p2 -> next;
        p1 -> next -> next = (originNext)? originNext : p2;
        p1 = originNext;
    }

}
