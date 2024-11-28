/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if(root){
        if(root -> left && root -> right){
            root -> left -> next = root -> right;
        }
        struct Node* n = root -> next;
        if(root -> left || root -> right){
            while(n){
                if(n -> left) {
                    if(root -> right) root -> right -> next = n -> left;
                    else root -> left -> next = n -> left;
                    break;
                }
                else if(n -> right){
                    if(root -> right) root -> right -> next = n -> right;
                    else root -> left -> next = n -> right;
                    break;
                }
                n = n -> next;
            }
        }
        connect(root -> right);
        connect(root -> left);
    }
    return root;
}
