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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool helper(ListNode* head, TreeNode* root, ListNode* H){
        if(!head) return true;
        if(!root) return false;

        if(head -> val == root -> val){
            if(helper(head -> next, root -> left, H)) return true;
            if(helper(head -> next, root -> right, H)) return true;
        }
        if(head == H) return helper(head, root -> left, H) || helper(head, root -> right, H);

        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return helper(head, root, head);
    }
};
