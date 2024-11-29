/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!(head -> next)) return head;
        /* Partition to two halves */
        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast && fast -> next){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;

        /* Reverse the second half */
        ListNode* tail = NULL;
        ListNode* originNext = NULL, *newNext = NULL;
        while(slow){
            originNext = slow -> next;
            slow -> next = newNext;
            newNext = slow;
            tail = slow;
            slow = originNext;
        }

        /* Check */
        ListNode* p1 = head, *p2 = tail;
        while(p1){
            if(p1 -> val != p2 -> val) return false;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return true;
    }
};
