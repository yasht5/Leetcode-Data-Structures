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
    
    TreeNode *solve(vector<int>& nums, int l, int h)
    {
        int size = h - l;
        if(size<0)
        {
            return NULL;
        }
        if(size==0)
        {
            return new TreeNode(nums[l]);
        }
        int mid = (l+h)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, l, mid-1);
        root->right = solve(nums, mid+1, h);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int h= n-1;
        TreeNode *root = solve(nums, l, h);
        return root;
    }
};
