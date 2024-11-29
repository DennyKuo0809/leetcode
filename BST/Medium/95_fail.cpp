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
    vector< vector< vector<TreeNode*> > >  mem;

    void helper(int start, int end){
        if(start >= end) return;
        if(mem[start][end].size()) return;

        for(int i = start ; i <= end ; i ++){
            helper(start, i-1);
            helper(i+1, end);
            for(TreeNode* p: mem[start][i-1]){
                for(TreeNode* q: mem[i+1][end]){
                    mem[start][end].push_back(
                        new TreeNode(i, p, q)
                    );
                }
            }
        }
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        for(int i = 0 ; i <= n+1 ; i ++){
            mem.push_back(vector< vector<TreeNode*> >());
            for(int j = 0 ; j <= n+1 ; j ++){
                mem[i].push_back(vector<TreeNode*>());
                if(i == j) mem[i][j].push_back(new TreeNode(i));
                else if(i > j) mem[i][j].push_back(NULL);
            }
        }

        helper(1, n);
        return mem[1][n];
    }
};
