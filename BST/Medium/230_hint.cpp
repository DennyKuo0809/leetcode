/**********************************************************************************
 * Follow up: 
 * If the BST is modified often (i.e., we can do insert and delete operations) 
 * and you need to find the kth smallest frequently, how would you optimize?
 *
 * Ans:  Record the number of nodes of each sub-tree. 
 *       (Recursion) If the number of nodes of the left sub-tree exceeds k, 
 *                   find the answer in the left sub-tree.
 *                   Otherwise, find it in the right sub-tree.
 **********************************************************************************/

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

    int nodes[10001];
    int index;
    void inorder(TreeNode* root){
        if(root -> left) inorder(root -> left);
        nodes[index] = root -> val;
        index ++;
        if(root -> right) inorder(root -> right);
    }
    int kthSmallest(TreeNode* root, int k) {
        index = 1;
        inorder(root);
        return nodes[k];
    }
};
