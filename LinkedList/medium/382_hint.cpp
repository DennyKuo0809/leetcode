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
    ListNode* start;
    Solution(ListNode* head) {
        start = head;
    }
    
    int getRandom() {
        ListNode* p = start;
        int ans = 0;
        double cnt = 1;
        for( ; p ; p = p -> next, cnt ++){
            double r = rand() / (RAND_MAX + 1.0);
            if(r <= (double)1 / cnt) ans = p -> val;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
