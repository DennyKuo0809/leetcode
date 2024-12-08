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
    ListNode* doubleIt(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ans = head;
        if(head -> val >= 5) ans = new ListNode(1, head);
        while(ptr){
            ptr -> val = ((ptr -> val) * 2) % 10;
            if(ptr -> next && ptr -> next -> val >= 5) ptr -> val ++;
            ptr = ptr -> next;
        }
        return ans;
    }
};
