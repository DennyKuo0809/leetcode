/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        bool firstItA = true, firstItB = true;
        while(pa && pb){
            if(pa == pb) return pa;
            if(pa -> next == NULL && firstItA){
                pa = headB;
                firstItA = false;
            }
            else pa = pa -> next;

            if(pb -> next == NULL && firstItB){
                pb = headA;
                firstItB = false;
            }
            else pb = pb -> next;
        }
        return NULL;
    }
};
