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
    stack<TreeNode*> P;
    vector<int> res;
    vector<TreeNode*> path;

    bool dfs_find_ancestor(TreeNode* src, TreeNode* target){
        P.push(src);
        if(src == target) return true;
        if(src -> left) {
            if(dfs_find_ancestor(src -> left, target)) return true;
        }
        if(src -> right) {
            if(dfs_find_ancestor(src -> right, target)) return true;
        }
        P.pop();
        return false;
    }

    void bfs_find_depth(TreeNode* src, int depth, TreeNode* ignore){
        if(depth == 0){
            res.push_back(src -> val);
            return;
        }
        if(depth == 1){
            if(src -> right != ignore && src -> right) res.push_back(src -> right -> val);
            if(src -> left != ignore && src -> left) res.push_back(src -> left -> val);
            return;
        }
        queue<vector<TreeNode*> > q;
        vector<TreeNode*> vec_;
        if(src -> right != ignore && src -> right) vec_.push_back(src -> right);
        if(src -> left != ignore && src -> left) vec_.push_back(src -> left);
        if(vec_.size()) q.push(vec_);
        
        int d = 2;
        while(!q.empty()){
            vector<TreeNode*> vec;
            if(d == depth){
                for(int i = 0 ; i < q.front().size() ; i ++){
                    TreeNode* tmp = q.front()[i];
                    if(tmp -> left) res.push_back(tmp -> left -> val);
                    if(tmp -> right) res.push_back(tmp -> right -> val);
                }
                break;
            }
            for(int i = 0 ; i < q.front().size() ; i ++){
                TreeNode* tmp = q.front()[i];
                if(tmp -> left) vec.push_back(tmp -> left);
                if(tmp -> right) vec.push_back(tmp -> right);
            }
            if(vec.size() > 0) q.push(vec);
            q.pop();
            d ++;
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0){
            res.push_back(target->val);
            return res;
        }
        dfs_find_ancestor(root, target);

        
        while(!P.empty()){
            path.push_back(P.top());
            P.pop();
        }

        int l = path.size();
        for(int i = 0, d = k ; i < l && d >= 0; i ++, d--){
            if(i == 0) bfs_find_depth(path[i], d, path[i]);
            else bfs_find_depth(path[i], d, path[i-1]);
        }
        
        return res;
    }
};
