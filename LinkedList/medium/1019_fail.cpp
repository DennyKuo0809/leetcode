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
    stack<pair<ListNode*, int>> s;
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        for(ListNode* p = head ; p ; p = p -> next){
            ans.push_back(0);
        }

        int cnt = 0;
        ListNode *p = head;
        for(; p ; p = p -> next, cnt ++){
            while(!s.empty()){
                if(s.top().first -> val < p -> val){
                    ans[s.top().second] = p -> val;
                    s.pop();
                }
                else break;
            }
            s.push(make_pair(p, cnt));
        }

        return ans;
    }
};
