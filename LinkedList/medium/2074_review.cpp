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
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* ptr = start;
        ListNode* originNext = NULL, *newNext = NULL;
        while(ptr != end){
            originNext = ptr -> next;
            ptr -> next = newNext;
            newNext = ptr;
            ptr = originNext;
        }
        if(end) {
            end -> next = newNext;
            return end;
        }
        return newNext;
        
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int gindex = 1;
        int index = 1;
        ListNode* ptr = head, *last = NULL;
        int end = 1;
        ListNode* start = head;
        for( ; ptr ; index ++){
            ListNode* originNext = ptr -> next;
            if(index == 1) start = ptr;
            if(index == gindex) {
                if(gindex % 2) last = ptr;
                else {
                    reverse(start, ptr);
                    last -> next = ptr;
                    start -> next = originNext;
                    last = start;
                } 
                gindex ++;
                index = 0;
            }
            ptr = originNext;
        }
        if(index > 1 && index % 2 == 1) last -> next = reverse(start, NULL);
        return head;
    }
};
