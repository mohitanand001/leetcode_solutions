/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        
        if(root == nullptr)
            return 0;
        
        
        int max_depth = 0;
        vector<Node*> childs = root->children;
        
        for(int i = 0; i < childs.size(); i++)
        {
            max_depth = max(max_depth, maxDepth(childs[i]));
        }
        
        max_depth++;
        return max_depth;
        
    }
};