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
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    bool valid(int r, int c, int m, int n){
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int> > ans(m, vector<int>(n, -1));
        int r = 0, c = 0;
        ListNode* ptr = head;
        int dir = 0;
        while(ptr){
            ans[r][c] = ptr -> val;
            int newr = r + dr[dir], newc = c + dc[dir];
            if(!valid(newr, newc, m, n) || ans[newr][newc] >= 0){
                dir = (dir + 1) % 4;
                newr = r + dr[dir];
                newc = c + dc[dir];
            }
            r = newr;
            c = newc;
            ptr = ptr -> next;
        }
        return ans;
    }
};
