/********************************************
 * Make the copy of the nodes interleaving 
 * with the original ones.
 ********************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* ptr = head;
        while(ptr){
            Node* tmp = new Node(ptr -> val);
            Node* originNext = ptr -> next;
            ptr -> next = tmp;
            tmp -> next = originNext;
            ptr = originNext;
        }

        ptr = head;
        while(ptr){
            ptr -> next -> random = (ptr -> random)?(ptr -> random -> next): NULL;
            ptr = ptr -> next -> next;
        }

        ptr = head -> next -> next;
        Node* ans = head -> next, *cur = ans;
        Node* originCur = head;
        bool origin = true;
        while(ptr){
            if(origin){
                originCur -> next = ptr;
                originCur = ptr;
            }
            else{
                cur -> next = ptr;
                cur = ptr;
            }
            origin ^= 1;
            ptr = ptr -> next;
        }
        originCur -> next = NULL;
        cur -> next = NULL;
        return ans;
    }
};
