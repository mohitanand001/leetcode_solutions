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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == nullptr and root2 == nullptr)
            return nullptr;
        
        TreeNode* new_node;
        
        if(root1 == nullptr)
        {
            new_node = new TreeNode(root2->val);
            new_node->left = mergeTrees(new_node->left, root2->left);
            new_node->right = mergeTrees(new_node->right, root2->right);
            
            return new_node;
        }
        else if(root2 == nullptr)
        {
            root1->left = mergeTrees(root1->left, nullptr);
            root1->right = mergeTrees(root1->right, nullptr);
        }
        else
        {
            root1->val+= root2->val;
            
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            
        }
        
        return root1;
    }
};