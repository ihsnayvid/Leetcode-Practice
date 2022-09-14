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
    vector<string> ans;
    
    void dfs(TreeNode *root, string ds){
        if(!root) return;
        if(!root->left and !root->right){
            ans.push_back(ds + to_string(root->val));
            return;
        }        
        
        dfs(root->left, ds + to_string(root->val) + "->");    
        dfs(root->right, ds + to_string(root->val) + "->");        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string ds = "";
        dfs(root, ds);
        return ans;
    }
};