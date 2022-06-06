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
    void get_width(TreeNode* root, map<int, unsigned long long> &mp, int level, unsigned long long width, unsigned long long &mx)
    {
        if(root == nullptr)
            return;
        
        if(mp.find(level) == mp.end())
        {
            mp[level] = width;
        }
        else
        {
            mx = max(mx*1ULL, width - mp[level]);
        }
        
        get_width(root->left, mp, level + 1, width * 2 + 1, mx);
        get_width(root->right, mp, level + 1, width * 2 + 2, mx);
        
    }
    
    int widthOfBinaryTree(TreeNode* root) {
     
        map<int, unsigned long long> mp;
        
        unsigned long long max_width = 0;
        
        get_width(root, mp, 0, 0, max_width);
        
        return max_width + 1;
    }
};