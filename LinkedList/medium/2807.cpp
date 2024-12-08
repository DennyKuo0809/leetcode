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
    int gcd(int big, int small){
        if(big % small == 0) return small;
        return gcd(small, big % small);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head, *last = NULL;
        while(curr){
            if(last){
                last -> next = new ListNode(gcd(last -> val, curr -> val));
                last -> next -> next = curr;
            }
            last = curr;
            curr = curr -> next;
        }
        return head;
    }
};
