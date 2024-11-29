/* Constant Extra Space - Merge Sort for Linked List */

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
    ListNode* sortList(ListNode* head) {
        /* Edge Cases */
        if(!head || !(head -> next)) return head;
        if(!(head -> next -> next)){
            if(head -> next -> val < head -> val){
                ListNode* ptr = head -> next;
                ptr -> next = head;
                head -> next = NULL;
                return ptr;
            }
            return head;
        }

        /* Split the list into two half */
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast && fast -> next){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;

        /* Divide & Conquer */
        ListNode* l = sortList(head);
        ListNode* r = sortList(slow);

        /* Merge */
        ListNode* ans = NULL;
        ListNode *pl = l, *pr = r;
        ListNode *tail = NULL;
        while(pl && pr){
            if(pl -> val <= pr -> val){
                if(!ans) ans = tail = pl;
                else {
                    tail -> next = pl;
                    tail = pl;
                }
                pl = pl -> next;
            }
            else{
                if(!ans) ans = tail = pr;
                else {
                    tail -> next = pr;
                    tail = pr;
                }
                ListNode *originNext = pr -> next;
                pr -> next = pl;
                pr = originNext;
            }
        }
        if(pl && tail) tail -> next = pl;
        if(pr && tail) tail -> next = pr;

        return ans;
    }
};
