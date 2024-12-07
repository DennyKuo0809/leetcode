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
    unordered_map<int, ListNode*> m;
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return NULL;
        ListNode  *ptr = head, *ans = head;
        ListNode* dummyHead = new ListNode(0, head);
        m[0] = dummyHead;
        int prefix = 0;
        while(ptr){
            prefix += (ptr -> val);
            if(m.find(prefix) != m.end()) {
                int toDelete = prefix + m[prefix] -> next -> val;
                while(toDelete != prefix && m.find(toDelete) != m.end()){
                    int tmp = toDelete;
                    toDelete += m[toDelete] -> next -> val;
                    m.erase(tmp);
                }
                m[prefix] -> next = ptr -> next;
            }
            else m[prefix] = ptr;
            ptr = ptr -> next;
        }

        return dummyHead -> next;
    }
};
