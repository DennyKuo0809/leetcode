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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head -> next)) return head;
        ListNode* odd = head, *oddCur = head;
        ListNode* even = head -> next, *evenCur = head -> next;
        bool oddd = true;
        ListNode* ptr = head -> next -> next;
        head -> next = NULL;
        while(ptr){
            if(oddd) {
                oddCur -> next = ptr;
                oddCur = ptr;
            }
            else {
                evenCur -> next = ptr;
                evenCur = ptr;
            }
            ptr = ptr -> next;
            oddd ^= 1;
        }
        oddCur -> next = even;
        evenCur -> next = NULL;
        return head;
    }
};
