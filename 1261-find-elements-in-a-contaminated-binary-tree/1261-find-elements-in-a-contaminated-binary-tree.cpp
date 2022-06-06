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
class FindElements {
public:
    set <int> s;
    void recover(TreeNode* root, int val, set<int> &s)
    {
        if(root == nullptr)
            return;
        
        root->val = val;
        s.insert(val);
        
        recover(root->left, val * 2 + 1, s);
        recover(root->right, val * 2 + 2, s);
        
    }
    
    
    FindElements(TreeNode* root) {
        s.clear();
        recover(root, 0, s);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */