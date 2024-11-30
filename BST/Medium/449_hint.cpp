/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void encode(TreeNode* root, string& s){ /* Preordered Traversal */
        if(!root) return;
        int num = root -> val;
        string tmp = "";
        while(num){
            tmp += (num % 10) + '0';
            num /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        s += tmp;
        s += "#";
        encode(root -> left, s);
        encode(root -> right, s);
    }

    TreeNode* decode(vector<int>& vec, int start, int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(vec[start], NULL, NULL);
        int bound = start + 1;
        while(bound <= end && vec[bound] < vec[start]){
            bound ++;
        }
        root -> left = decode(vec, start+1, bound-1);
        root -> right = decode(vec, bound, end);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        encode(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vec;
        int num = 0;
        for(int i = 0 ; i < data.length() ; i ++){
            if(data[i] == '#') {
                vec.push_back(num);
                num = 0;
            }
            else num = (num * 10) + data[i] - '0';
        }
        return decode(vec, 0, vec.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
