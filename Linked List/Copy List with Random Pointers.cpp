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
        map<Node*, Node*> mp;
        Node *curr = head;
        Node *help;
        while(curr)
        {
            help = new Node(curr->val);
            help->next = NULL;
            help->random = NULL;
            mp[curr] = help;
            curr = curr->next;
        }
        curr = head;
        
        while(curr)
        {
            help = mp[curr];
            help->next = mp[curr->next];
            help->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];    
    }
};
