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
    vector<int> help;
    void inorder(TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left);
        help.push_back(root->val);
        inorder(root->right);
            
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int n = help.size();
        for(int i=1;i<n;i++)
        {
            if(help[i]<=help[i-1])
            {
                return false;
            }
        }
        return true;
    }
};
