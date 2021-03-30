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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()){
            TreeNode* t1 = q.front();
            q.pop();
            if(t1==NULL){
                res.push_back(v);
                v.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                v.push_back(t1->val);
                if(t1->left)
                    q.push(t1->left);
                if(t1->right)
                    q.push(t1->right);
            }
            
        }
        return res;
    }
};
