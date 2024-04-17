

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
    string curr = "";
    string small = "";

    string smallestFromLeaf(TreeNode* root) {
        curr += (char)(root -> val + 'a');
        if(!(root -> left) && !(root -> right)){
            reverse(curr.begin(), curr.end());
            if(small == "" || curr < small) small = curr;
            reverse(curr.begin(), curr.end());
        }
        if(root -> left) smallestFromLeaf(root -> left);
        if(root -> right) smallestFromLeaf(root -> right);
        curr.pop_back();
        return small;
    }
};
