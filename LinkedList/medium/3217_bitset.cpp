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
    bitset<100001> clear;
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(int num: nums) clear[num] = 1;
        ListNode* ans = head, *cur = head, *last = NULL;
        while(cur){
            ListNode* originNext = cur -> next;
            if(clear[cur -> val]){
                if(last) last -> next = cur -> next;
                else ans = cur -> next;
            }
            else last = cur;
            cur = originNext;
        }
        return ans;
    }
};
