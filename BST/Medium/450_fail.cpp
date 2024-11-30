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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
            return root;
        }
        
        /* key == root -> val */
        if(!root -> right) return root -> left;
        if(!root -> left) return root -> right;
        TreeNode *n = root -> right;
        while(n && n -> left) n = n -> left;
        n -> left = root -> left;
        return root -> right;
    }
};
