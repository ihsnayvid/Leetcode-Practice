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
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            while(s--){
                auto curr = q.front();
                q.pop();
                for(auto i: curr->children)
                    q.push(i);
                level.push_back(curr->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};