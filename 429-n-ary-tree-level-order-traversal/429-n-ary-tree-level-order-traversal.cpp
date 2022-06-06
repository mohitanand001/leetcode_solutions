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
    vector<vector<int>> levelOrder(Node* root) {
     
        queue<Node*> q;
        vector<vector<int> > ans;
        vector<int> level;
        
        if(root == nullptr)
            return ans;
        
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            level.clear();
            for(int i = 1; i <= n; i++)
            {
                Node* front = q.front();
                q.pop();
                level.push_back(front->val);
                for(int i = 0; i < front->children.size(); i++)
                {
                    // if(front->children[i])
                        q.push(front->children[i]);
                }
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};