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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
        {
            return res;
        }
        queue<Node*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty())
        {
            int n = q.size();
            while(n>0)
            {
                Node *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                
                for(int i=0;i<curr->children.size();i++)
                {
                    q.push(curr->children[i]);
                }
                n--;
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;    
    }
};
