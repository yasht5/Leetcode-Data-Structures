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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        queue<TreeNode *> q;
        
        q.push(root);
        q.push(root);
        while(!q.empty())
        {
            TreeNode *curr1 = q.front();
            q.pop();
            TreeNode *curr2 = q.front();
            q.pop();
            
            if(!curr1 && !curr2)
            {
                continue;
            }
            if(!curr1 || !curr2)
            {
                return false;
            }
            if(curr1->val != curr2->val)
            {
                return false;
            }
            
            q.push(curr1->left);
            q.push(curr2->right);
            q.push(curr1->right);
            q.push(curr2->left);
            
        }
        return true;
    }
};
