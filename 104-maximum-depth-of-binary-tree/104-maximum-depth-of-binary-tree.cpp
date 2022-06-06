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
    int maxDepth(TreeNode* root) {
     
        if(root == nullptr)
            return 0;
        
        if(root->left == nullptr and root->right == nullptr)
            return 1;
        
        if(root->left == nullptr)
            return 1 + maxDepth(root->right);
        
        if(root->right == nullptr)
            return 1 + maxDepth(root->left);
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};