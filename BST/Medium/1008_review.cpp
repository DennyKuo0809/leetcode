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
    TreeNode* convert(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start], NULL, NULL);
        int bound = start + 1;
        while(bound <= end && preorder[bound] < preorder[start]){
            bound ++;
        }
        root -> left = convert(preorder, start+1, bound-1);
        root -> right = convert(preorder, bound, end);
        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return convert(preorder, 0, preorder.size()-1);
    }
};
