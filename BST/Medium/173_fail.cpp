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
class BSTIterator {
public:
    TreeNode *it, *nextIt;
    stack<TreeNode*> path;
    BSTIterator(TreeNode* root) {
        TreeNode* n = root;
        while(n){
            path.push(n);
            n = n -> left;
        }
        /* Non-existent smallest number */
        it = new TreeNode(-1, NULL, NULL);
        path.push(it);
        nextIt = NULL;
    }
    
    int next() {
        if(hasNext()) {
            it = nextIt;
            nextIt = NULL;
        }
        return it -> val;
    }
    
    bool hasNext() {
        if(nextIt) return true;
        if(it -> right){
            TreeNode *n = it -> right;
            while(n){
                path.push(n);
                nextIt = n;
                n = n -> left;
            }
            return true;
        }
        else{
            while(!path.empty()){
                if(path.top() -> val > it -> val) {
                    nextIt = path.top();
                    return true;
                }
                path.pop();
            }
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
