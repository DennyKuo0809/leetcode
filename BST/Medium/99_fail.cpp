/* Preprocessing: Inorder Traversal */


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
    TreeNode* n[1000];
    int cnt = 0;
    void inorder(TreeNode* root){
        if(root -> left) inorder(root -> left);
        n[cnt++] = root; 
        if(root -> right) inorder(root -> right);
    }

    void recoverTree(TreeNode* root) {
        cnt = 0;
        inorder(root);
        TreeNode *p1 = NULL, *p2 = NULL;
        for(int i = 0 ; i < cnt-1 ; i ++){
            if(n[i] -> val > n[i+1] -> val){
                if(!p1){
                    p1 = n[i];
                    p2 = n[i+1];
                }
                else {
                    p2 = n[i+1];
                    break;
                }
            }
        }
        int tmp = p1 -> val;
        p1 -> val = p2 -> val;
        p2 -> val = tmp;
    }
};
