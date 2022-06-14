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
    void solve(TreeNode* root, string path, vector<string> &paths)
    {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr and root->right == nullptr)
        {
            paths.push_back(path + to_string(root->val));
            return;
        }
        
        path = path + to_string(root->val) + "->";
        
        solve(root->left, path, paths);
        solve(root->right, path, paths);
        
        path.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> paths;
        string path = "";
        
        solve(root, path, paths);
        
        return paths;
        
    }
};