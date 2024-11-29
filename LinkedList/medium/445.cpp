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
    ListNode* reverseList(ListNode* l){
        ListNode *p = l;
        ListNode *originNext = NULL, *newNext = NULL;
        while(p){
            originNext = p -> next;
            p -> next = newNext;
            newNext = p;
            p = originNext;
        }
        return newNext;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = NULL, *sumCur = NULL;
        ListNode* p1 = reverseList(l1);
        ListNode* p2 = reverseList(l2);

        int carry = 0;
        while(p1 || p2){
            int num = carry;
            if(p1){
                num += p1 -> val;
                p1 = p1 -> next;
            }
            if(p2){
                num += p2 -> val;
                p2 = p2 -> next;
            }
            ListNode* node = new ListNode(num % 10, NULL);
            if(sum) {
                sumCur -> next = node;
                sumCur = node;
            }
            else sumCur = sum = node;
            carry = num / 10;
        }
        if(carry){
            ListNode* node = new ListNode(carry, NULL);
            sumCur -> next = node;
        }
        return reverseList(sum);
        
    }
};
