/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root) {
    if(!root) return;
    struct TreeNode* tmp = root -> right;
    flatten(root -> left);
    flatten(root -> right);
    root -> right = root -> left;
    struct TreeNode* x = root;
    while(x -> right) x = x -> right;
    x -> right = tmp;
    root -> left = NULL;
}
