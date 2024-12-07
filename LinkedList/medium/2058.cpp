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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ans.push_back(100001);
        ans.push_back(-1);
        ListNode* ptr = head;
        int index = 0, last = -1, first = -1;
        int lastVal = 0;
        for( ; ptr ; index ++, ptr = ptr -> next){
            if(lastVal && ptr -> next){
                if(
                    (ptr -> val < lastVal && ptr -> val < ptr -> next -> val) || 
                    (ptr -> val > lastVal && ptr -> val > ptr -> next -> val)){
                        if(first < 0) first = index;
                        else ans[1] = max(ans[1], index - first);
                        if(last >= 0) ans[0] = min(ans[0], index - last);
                        last = index;
                    }
            }
            lastVal = ptr -> val;
        }
        if(ans[0] == 100001) ans[0] = -1;
        return ans;
    }
};
