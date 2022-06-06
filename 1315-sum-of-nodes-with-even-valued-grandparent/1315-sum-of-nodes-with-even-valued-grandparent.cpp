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
    
    void get_sum(TreeNode* root, int &count)
    {
        if(root == nullptr)
            return;
        
        if(root->val % 2 == 0)
        {
            if(root->left)
            {
                if(root->left->left)
                    count += (root->left->left->val);
                if(root->left->right)
                    count += (root->left->right->val);
            }
            
            if(root->right)
            {
                if(root->right->left)
                    count+= (root->right->left->val);
                if(root->right->right)
                    count+= (root->right->right->val);
            }
        }
        get_sum(root->left, count);
        get_sum(root->right, count);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        
        int count = 0;
        get_sum(root, count);
        
        return count;
    }
};