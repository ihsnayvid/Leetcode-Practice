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
    vector<int> preorder(Node* root) {
        if(!root) return {};
        stack<Node*> st;
        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            int s = st.size();
            while(s--){
                auto curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                for(int i = curr->children.size() - 1; i>=0; i--)
                    st.push(curr->children[i]);
            }
        }
        return ans;
    }
};