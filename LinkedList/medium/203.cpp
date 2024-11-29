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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* prev = NULL;
        ListNode* ans = NULL;
        while(p){
            if(p -> val == val){
                if(prev) prev -> next = p -> next;
            }
            else {
                prev = p;
                if(!ans) ans = p;
            }
            p = p -> next;
        }
        return ans;
    }
};
