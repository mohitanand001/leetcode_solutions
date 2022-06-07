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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool x_exist = false, y_exist = false;
        
        while(!q.empty())
        {
            int n = q.size();
            x_exist = false;
            y_exist = false;
            for(int i = 1; i <= n; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                
                if(front->val == x)
                    x_exist = true;
                if(front->val == y)
                    y_exist = true;
                
                
                if(front->left and front->right)
                {
                    if(front->left->val == x and front->right->val == y)
                        return false;
                    
                    if(front->left->val == y and front->right->val == x)
                        return false;
                }
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            
            if(x_exist and y_exist)
                return true;
        }
        
        return false;
    }
};