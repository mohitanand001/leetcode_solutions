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
    
    void find_mode(TreeNode* root, map<int, int> &frq)
    {
        if(root == nullptr)
            return;
        
        frq[root->val]++;
        find_mode(root->left, frq);
        find_mode(root->right, frq);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;        
        map<int, int> frq;
        
        if(root == nullptr)
            return ans;
        
        find_mode(root, frq);
        int max_ = 1;
        
        for(auto node: frq)
        {
            max_ = max(max_, node.second);
        }
        
        for(auto node: frq)
        {
            if(node.second == max_)
                ans.push_back(node.first);
        }
        
        return ans;
    }
};