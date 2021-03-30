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
    vector<int> res;
    void pre(TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        res.push_back(root->val);
        pre(root->left);
        pre(root->right);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return res;
    }
};
