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
    Node* flatten(Node* head) {
        if(!head)
        {
            return NULL;
        }
        
        Node* curr = head;
        while(curr)
        {
            if(curr->child)
            {
                Node *next = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                Node *tail = curr->next;
                while(tail->next)
                {
                    tail = tail->next;
                }
                tail->next = next;
                if(next)
                    next->prev = tail;
            }
            curr = curr->next;
        }
        return head;
    }
};
