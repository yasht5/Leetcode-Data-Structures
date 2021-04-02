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
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        TreeNode *curr = s.top();
        s.pop();
        pushleft(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        if(s.empty())
        {
            return false;
        }
        return true;
    }
    void pushleft(TreeNode *root)
    {
        if(root)
        {
            s.push(root);
            pushleft(root->left);
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
