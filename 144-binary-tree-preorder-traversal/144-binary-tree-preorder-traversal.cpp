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
    void preorder(TreeNode* root, vector<int> &ans){
        stack<TreeNode*> st;
        if(!root) return;
        st.push(root);
        while(!st.empty()){
            for(int i=0; i<st.size(); i++){
                TreeNode* curr = st.top();
                st.pop();
                if(curr->right) st.push(curr->right);
                if(curr->left) st.push(curr->left);                
                ans.push_back(curr->val);
            }
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};