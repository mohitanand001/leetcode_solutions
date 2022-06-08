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
    void get_vals(TreeNode* root, vector<int> &vals)
    {
        if(root == nullptr)
            return;
        
        
        get_vals(root->left, vals);
        vals.push_back(root->val);
        get_vals(root->right, vals);
    }
    
    TreeNode* construct(vector<int> &vals, int i, int j)
    {
        if(i > j)
        {
            return nullptr;
        }
        
        int mid = (i + j) / 2;
        
        TreeNode* rt = new TreeNode(vals[mid]);
        
        rt->left = construct(vals, i, mid - 1);
        rt->right = construct(vals, mid + 1, j);
        
        return rt;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> vals;
        
        get_vals(root, vals);
        
        TreeNode* root1 = construct(vals, 0, vals.size() - 1);
        
        return root1;
    }
};