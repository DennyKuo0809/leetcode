/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* helper(Node* head){
        Node *p = head, *tail = NULL;
        while(p){
            Node *originNext = p -> next;
            if(p -> child){
                p -> child -> prev = p;
                p -> next = p -> child;
                tail = helper(p -> child);
                tail -> next = originNext;
                if(originNext) originNext -> prev = tail;
                p -> child = NULL;
            }
            else tail = p;
            p = originNext;
        }
        return tail;
    }

    Node* flatten(Node* head) {
        Node* p = head;
        helper(head);
        return head;
    }
};
