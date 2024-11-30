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
    stack<TreeNode*> s;

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(findTarget(root -> left, k)) return true;
         
        while(!s.empty()){
            if(s.top() -> val + root -> val == k) return true;
            else if(s.top() -> val + root -> val > k) s.pop();
            else break;
        }
        s.push(root);

        if(findTarget(root -> right, k)) return true;

        return false;
    }
};
