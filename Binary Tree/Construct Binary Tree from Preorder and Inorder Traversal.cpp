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
    int n;
    int pos;
    map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        
        n = preorder.size();
        pos = 0;
        
        return build(inorder, preorder, 0, n-1);
    }
    
    TreeNode *build(vector<int>& in, vector<int>& pre, int start, int end)
    {
        if(start>end )//|| pos>=n)
        {
            return NULL;
        }
        
        TreeNode *curr = new TreeNode(pre[pos]);
        pos++;
        if(start == end)
        {
            return curr;
        }
        
        int indx = mp[curr->val];
        curr->left = build(in, pre, start, indx-1);
        curr->right = build(in, pre, indx+1, end);
        return curr;
    }
};
