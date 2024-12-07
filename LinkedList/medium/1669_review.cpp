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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = NULL, *end = NULL;
        int i =  0;
        ListNode* p = list1;
        for( ; p ; i ++, p = p -> next){
            if(i == a - 1) start = p;
            else if(i == b + 1) {
                end = p;
                break;
            }
        }
        if(start){
            start -> next = list2;
        }
        if(end){
            p = list2;
            ListNode* tail = start;
            while(p){
                tail = p;
                p = p -> next;
            }
            if(tail) tail -> next = end;
        }
        return (a == 0)? list2 : list1;
    }
};
