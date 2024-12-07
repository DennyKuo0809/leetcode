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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = NULL, *cur = NULL;
        ListNode* ptr = head;
        int sum = 0;
        while(ptr){
            if(ptr -> val == 0){
                if(sum){
                    ListNode* n = new ListNode(sum);
                    if(!ans) ans = cur = n;
                    else {
                        cur -> next = n;
                        cur = n;
                    }
                    sum = 0;
                }
            }
            else sum += (ptr -> val);
            ptr = ptr -> next;
        }
        return ans;
    }
};
