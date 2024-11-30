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
    
    vector<TreeNode*> vec;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        vec.push_back(root);
        inorder(root -> right);
    }

    TreeNode* rebuild(int l, int r){
        if(l >= r) return NULL;
        if(l == r-1) return new TreeNode(vec[l] -> val, NULL, NULL);
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(
            vec[mid] -> val, 
            rebuild(l, mid), 
            rebuild(mid+1, r)
        );
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return rebuild(0, vec.size());
    }
};
