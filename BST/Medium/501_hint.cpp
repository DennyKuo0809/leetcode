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

    int mostNum = 0;
    int currentVal = 1e5+1;
    int currentCnt = 0;
    
    void inorder_p1(TreeNode* root){
        if(!root) return;
        inorder_p1(root -> left);
        if(root -> val == currentVal) currentCnt ++;
        else{
            currentVal = root -> val;
            currentCnt = 1;
        }
        mostNum = max(currentCnt, mostNum);
        inorder_p1(root -> right);
    }

    void inorder_p2(TreeNode* root, vector<int>& ans){
        if(!root) return;
        inorder_p2(root -> left, ans);
        if(root -> val == currentVal) currentCnt ++;
        else{
            currentVal = root -> val;
            currentCnt = 1;
        }
        if(currentCnt == mostNum) ans.push_back(currentVal);
        inorder_p2(root -> right, ans);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder_p1(root);
        currentVal = 1e5+1;
        inorder_p2(root, ans);
        return ans;
    }
};
