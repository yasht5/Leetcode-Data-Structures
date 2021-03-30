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
    map<int, int> mp;
    int pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
            
        }
        
        int n = postorder.size();
        
        pos = n-1;
        
        return build(inorder, postorder, 0, n-1);
    }
    
    TreeNode *build(vector<int>& in, vector<int>& post, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(post[pos]);
        pos--;
        if(start == end)
        {
            return node;
        }
        
        int index = mp[node->val];
        
        node->right = build(in, post, index+1, end);
        node->left = build(in, post, start, index-1);
        
        return node;
    }
};
