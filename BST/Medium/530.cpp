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
    int currentVal = -1e5 - 1;
    int minDiff = 1e5 + 1;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        int diff = abs(root -> val - currentVal);
        currentVal = root -> val;
        minDiff = min(minDiff, diff);
        inorder(root -> right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};
