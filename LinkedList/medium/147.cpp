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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = head;
        ListNode* ptr = head -> next, *ans = head;
        head -> next = NULL;
        while(ptr){
            ListNode *originNext = ptr -> next;
            ListNode *p = ans;
            ListNode *prev = NULL;
            bool insert = false;
            while(p){
                if(ptr -> val < p -> val){
                    if(prev) prev -> next = ptr;
                    else ans = ptr;
                    ptr -> next = p;
                    insert = true;
                    break;
                }
                prev = p;
                p = p -> next;
            }
            if(!insert){
                prev -> next = ptr;
                ptr -> next = NULL;
            }
            ptr = originNext;
        }

        return ans;
    }
};
