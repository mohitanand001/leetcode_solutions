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
    bool check_bst(TreeNode* root, TreeNode* min_, TreeNode* max_)
    {
        if(root == nullptr)
            return true;
        
        if(min_ and root->val <= min_->val)
            return false;
        
        if(max_ and root->val >= max_->val)
            return false;
        
        bool le = check_bst(root->left, min_, root);
        bool ri = check_bst(root->right, root, max_);
        
        return le and ri;
    }
    
    bool isValidBST(TreeNode* root) {
        
        return check_bst(root, nullptr, nullptr);
    }
};