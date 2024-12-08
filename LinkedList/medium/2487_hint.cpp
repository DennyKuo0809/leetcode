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
    stack<ListNode*> s;
    ListNode* removeNodes(ListNode* head) {
        if(!head) return head;
        ListNode* newNext = removeNodes(head -> next);
        if(newNext && newNext -> val > head -> val) return newNext;
        head -> next = newNext;
        return head;
    }
};
