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

    bool helper(TreeNode* root, long long int leftBound, long long int rightBound){
        if(!root) return true;
        if(root -> val <= leftBound || root -> val >= rightBound) return false;
        if(root -> left){
            if(root -> left -> val >= root -> val) return false;
            if(!helper(root -> left, leftBound, root -> val)) return false;
        }
        if(root -> right){
            if(root -> right -> val <= root -> val) return false;
            if(!helper(root -> right, root -> val, rightBound)) return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, (long long int)(INT_MIN) - 1, (long long int)(INT_MAX) + 1);
    }
};
