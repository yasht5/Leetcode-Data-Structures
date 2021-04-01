/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root)
        {
            return res;
        }
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node *curr = s.top();
            s.pop();
            for(int i = curr->children.size()-1;i>=0;i--)
            {
                s.push(curr->children[i]);
            }
            res.push_back(curr->val);
        }
        return res;
    }
};
