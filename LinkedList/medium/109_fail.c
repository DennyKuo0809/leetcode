/******************************************************
 * Use fast and slow pointer to figure out the middle 
 * node of the linked list quickly.
 ******************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedListToBST(struct ListNode* head) {
    if(!head) return NULL;
    if(!(head -> next)){
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node -> val = head -> val;
        node -> left = node -> right = NULL;
        return node;
    } 

    /* Try finding the middle node */
    struct ListNode *slow = head, *fast= head, *prev = NULL;
    while(fast && fast -> next){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    prev -> next = NULL; /* Split the linked list*/

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node -> val = slow -> val;
    node -> left = sortedListToBST(head);
    node -> right = sortedListToBST(slow -> next);
    return node;
}
