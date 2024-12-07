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
    int pairSum(ListNode* head) {
        int ans = 0;
        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast && fast -> next){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;

        /* Reverse the second part */
        ListNode* originNext = NULL, *newNext = NULL;
        while(slow){
            originNext = slow -> next;
            slow -> next = newNext;
            newNext = slow;
            slow = originNext;
        }

        /* Solve */
        for(ListNode* p1 = head, *p2 = newNext ; p1 && p2 ; p1 = p1 -> next, p2 = p2 -> next){
            ans = max(ans, p1 -> val + p2 -> val);
        }

        return ans;
    }
};
