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
    TreeNode* current = NULL;
    TreeNode* ans = NULL;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        if(current) current -> right = root;
        else ans = root;
        current = root;
        root -> left = NULL;
        inorder(root -> right);
    }


    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
