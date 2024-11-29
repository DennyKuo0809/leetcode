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
    ListNode* reverseList(ListNode* head) {
        ListNode *originNext = NULL, *newNext = NULL;
        ListNode *p = head, *ans = NULL;
        while(p){
            originNext = p -> next;
            p -> next = newNext;
            newNext = p;
            p = originNext;
        }
        return newNext;
    }
};
