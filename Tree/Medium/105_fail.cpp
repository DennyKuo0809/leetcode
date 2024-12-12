/* Solution 1: O(N^2) */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preSize, int* inorder, int inSize) {
    if(inSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = *preorder;
    int leftSize = 0;
    for( ; leftSize < inSize ; leftSize ++){
        if(inorder[leftSize] == *preorder) break;
    }

    root -> left = buildTree(preorder + 1, leftSize, inorder, leftSize);
    root -> right = buildTree(preorder + 1 + leftSize, inSize - leftSize - 1, inorder + 1 + leftSize, inSize - leftSize - 1);

    return root;
}


/* Solution 2: O(N) */
/* Quite tricky */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int i, p;
struct TreeNode* build(int* in, int* pre, int inSize, int preSize, int parentVal) {
    if(p >= preSize || i >= inSize || in[i] == parentVal) return NULL;
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = pre[p];
    p ++;
    root -> left = build(in, pre, inSize, preSize, root -> val);
    i ++;
    root -> right = build(in, pre, inSize, preSize, parentVal);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    i = p = 0;
    return build(inorder, preorder, inorderSize, preorderSize, INT_MIN);
}
