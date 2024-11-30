/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* small = (p -> val < q -> val)? p : q;
        TreeNode* big = (p -> val < q -> val)? q : p;

        TreeNode* n = root;
        while(n){
            if(n -> val > small -> val && n -> val < big -> val) return n;
            if(n -> val == small -> val) return small;
            if(n -> val == big -> val) return big;
            if(n -> val > big -> val) n = n -> left;
            else n = n -> right; 
        }
        return NULL;
    }
};
