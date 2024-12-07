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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 = head, *ptr2 = head;
        int i = 1;
        ListNode *swap;
        for( ; i <= k ; ptr1 = ptr1 -> next, i ++) swap = ptr1;
        for( ; ptr1 ; ptr1 = ptr1 -> next, ptr2 = ptr2 -> next);
        int tmp = swap -> val;
        swap -> val = ptr2 -> val;
        ptr2 -> val = tmp;
        return head;
    }
};
