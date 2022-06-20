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
    void visible(TreeNode* root, int curr_max, int &count)
    {
        if(root == nullptr)
            return;
        
        if(curr_max <= root->val)
            count++;
        
        visible(root->left, max(curr_max, root->val), count);
        visible(root->right, max(curr_max, root->val), count);
    }
    
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        
        visible(root, -10005, count);
        
        return count;
        
    }
};