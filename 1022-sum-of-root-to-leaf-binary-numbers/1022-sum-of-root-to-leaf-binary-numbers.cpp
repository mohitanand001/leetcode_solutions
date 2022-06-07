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
    void sum_total(TreeNode* root, int prev, int &total)
    {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr and root->right == nullptr)
        {
            total += prev * 2 + root->val;
            return;
        }
        
        sum_total(root->left, prev * 2 + root->val, total);
        sum_total(root->right, prev * 2 + root->val, total);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        int total = 0;
        
        sum_total(root, 0, total);
        return total;
    }
};