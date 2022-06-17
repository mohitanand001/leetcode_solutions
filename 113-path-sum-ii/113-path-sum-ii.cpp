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
    void solve(TreeNode* root, int target, int curr_sum, vector<vector<int> >& all_paths, vector<int>&curr_path)
    {
        if(root == nullptr)
            return;
        
        // cout << root->val << endl;
        
        if((root->left == nullptr) and (root->right == nullptr))
        {
            curr_sum += root->val;
            
            if(curr_sum == target)
            {
                curr_path.push_back(root->val);
                all_paths.push_back(curr_path);
                curr_path.pop_back();
            }
            
            return;
        }
        
        curr_path.push_back(root->val);
        
        solve(root->left, target, curr_sum + root->val, all_paths, curr_path);
        solve(root->right, target, curr_sum + root->val, all_paths, curr_path);
        
        curr_path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int> > all_paths;
        vector<int> curr_path;
        solve(root, targetSum, 0, all_paths, curr_path);
        
        return all_paths;
        
    }
};