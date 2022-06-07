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
    
    int get_dia(TreeNode* root, int &dia)
    {
        if(root == nullptr)
            return 0;
        
        int le = get_dia(root->left, dia);
        int ri = get_dia(root->right, dia);
        
        dia = max(dia, le + ri);
        
        return max(le, ri) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int dia = 0;
        
        get_dia(root, dia);
        return dia;
    }
};