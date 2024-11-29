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
    bool inNums[10001];
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0;
        for(int num: nums) inNums[num] = true;

        ListNode* p = head;
        bool consecutive = false;
        while(p){
            if(inNums[p -> val]){
                if(!consecutive){
                    ans ++;
                    consecutive = true;
                }
            }
            else consecutive = false;
            p = p -> next;
        }
        return ans;
    }
};
