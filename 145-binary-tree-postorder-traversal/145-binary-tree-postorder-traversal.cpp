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
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> st, st2;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st2.push(node);
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);  
        }
        while(!st2.empty()){
            TreeNode* node = st2.top();
            ans.push_back(node->val);
            st2.pop();
        }
        return ans;
    }
};