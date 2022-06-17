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
    
    bool has_path_sum(TreeNode* root, int target, int curr)
    {
        if(root == nullptr)
            return false;
        
        if(root->left  == nullptr and root->right == nullptr)
        {
            curr = curr + root->val;
            if(curr == target)
                return true;
            return false;
        }
        
        bool found_in_left = has_path_sum(root->left, target, curr + root->val);
        bool found_in_right = has_path_sum(root->right, target, curr + root->val);
        
        return found_in_left or found_in_right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool ans = has_path_sum(root, targetSum, 0);
        return ans;
        
    }
};